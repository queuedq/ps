#include <bits/stdc++.h>
#define endl "\n"
#define X first
#define Y second
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1'005;
int N, M, K, par[MN];
vector<pair<int, pii>> edge, T0, T1;

int find(int x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  par[y] = x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=0; i<M; i++) {
    char c; int f, t; cin >> c >> f >> t;
    edge.push_back({c == 'B', {f, t}});
  }

  sort(edge.begin(), edge.end());

  int C0 = 0;
  for (int i=1; i<=N; i++) par[i] = i;
  for (int i=0; i<M; i++) {
    if (find(edge[i].Y.X) == find(edge[i].Y.Y)) continue;
    merge(edge[i].Y.X, edge[i].Y.Y);
    T0.push_back(edge[i]);
    C0 += edge[i].X;
  }

  int C1 = 0;
  for (int i=1; i<=N; i++) par[i] = i;
  for (int i=M-1; i>=0; i--) {
    if (find(edge[i].Y.X) == find(edge[i].Y.Y)) continue;
    merge(edge[i].Y.X, edge[i].Y.Y);
    T1.push_back(edge[i]);
    C1 += edge[i].X;
  }
  reverse(T1.begin(), T1.end());

  if (K < C0 || C1 < K) {
    cout << 0 << endl;
    return 0;
  }

  int C = C0;
  vector<pair<int, pii>> T = T0;

  while (C != K) {
    for (auto [c, e]: T1) {
      auto it = lower_bound(T.begin(), T.end(), pair(c, e));
      if (*it != pair(c, e)) {
        T.insert(it, {c, e});
        C += c;
        break;
      }
    }

    sort(T.begin(), T.end());

    vector<vector<pii>> adj(N+1);
    vector<int> deg(N+1);
    for (auto [c, e]: T) {
      adj[e.X].push_back({e.Y, c});
      adj[e.Y].push_back({e.X, c});
      deg[e.X]++;
      deg[e.Y]++;
    }
    
    queue<int> Q;
    for (int i=1; i<=N; i++) {
      if (deg[i] == 1) Q.push(i);
    }

    while (!Q.empty()) {
      auto u = Q.front(); Q.pop();
      deg[u]--;
      for (auto [v, c]: adj[u]) {
        deg[v]--;
        if (deg[v] == 1) Q.push(v);
      }
    }

    for (int i=0; i<M+1; i++) {
      auto [c, e] = T[i];
      if (deg[e.X] == 2 && deg[e.Y] == 2 &&
          *lower_bound(T1.begin(), T1.end(), pair(c, e)) != pair(c, e)) {
        T.erase(T.begin() + i);
        C -= c;
        break;
      }
    }
  }

  for (auto [c, e]: T) {
    cout << e.X << " " << e.Y << endl;
  }

  ////////////////////////////////
  return 0;
}
