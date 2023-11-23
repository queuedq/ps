#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 50;

struct Flow {
  int N;
  vector<vector<int>> adj, cap;
  vector<int> par;

  Flow(int N): N(N) {
    adj.resize(N+1);
    cap.resize(N+1);
    for (int i=1; i<=N; i++) cap[i].resize(N+1);
    par.resize(N+1);
  }

  void add_edge(int u, int v, int c) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    cap[u][v] = c;
  }

  int bfs(int s, int t) {
    fill(all(par), 0);
    par[s] = -1;
    queue<pii> Q;
    Q.push({s, INT_MAX});

    while (!Q.empty()) {
      auto [u, f] = Q.front(); Q.pop();

      for (auto v: adj[u]) {
        if (par[v] != 0 || cap[u][v] == 0) continue;
        int f1 = min(f, cap[u][v]);
        par[v] = u;
        if (v == t) return f1;
        Q.push({v, f1});
      }
    }
    return 0;
  }

  int max_flow(int s, int t) {
    int f, sum = 0;

    while ((f = bfs(s, t))) {
      int u = t;
      while (u != s) {
        int p = par[u];
        cap[p][u] -= f;
        cap[u][p] += f;
        u = p;
      }
      sum += f;
    }
    return sum;
  }

  void update(int s, int t) {
    // use other path s->t other than edge (s, t)
    int f = bfs(s, t);
    if (f == 0) return;

    int u = t;
    while (u != s) {
      int p = par[u];
      cap[p][u] -= 1;
      cap[u][p] += 1;
      u = p;
    }

    cap[s][t] += 1;
    cap[t][s] -= 1;
  }
};

int R, C, ans[MN][MN];

bool solve() {
  cin >> R >> C;
  Flow F(R+C+2);
  int s = R+C+1, t = R+C+2;
  int ssum = 0, tsum = 0;

  for (int i=1, c; i<=R; i++) { cin >> c; F.add_edge(s, i, c); ssum += c; }
  for (int j=1, c; j<=C; j++) { cin >> c; F.add_edge(R+j, t, c); tsum += c; }

  if (ssum != tsum) return 0; // impossible

  for (int i=1; i<=R; i++)
    for (int j=1; j<=C; j++)
      F.add_edge(i, R+j, 1);

  // max flow
  int flow = F.max_flow(s, t);
  if (flow < ssum) return 0;

  // lexicographically smallest flow
  for (int i=1; i<=R; i++) {
    for (int j=1; j<=C; j++) {
      if (!F.cap[i][R+j]) F.update(i, R+j);
      ans[i][j] = !F.cap[i][R+j];
      F.cap[i][R+j] = F.cap[R+j][i] = 0; // protect flow
    }
  }

  return 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    bool ok = solve();

    cout << "Case #" << t << ": ";
    if (ok) {
      cout << "POSSIBLE" << endl;
      for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) cout << (ans[i][j] ? '/' : '\\');
        cout << endl;
      }
    } else {
      cout << "IMPOSSIBLE" << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
