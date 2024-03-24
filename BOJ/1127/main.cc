#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 55;
const int INF = 1e6;
int N, K, adj[MN][MN], guard[MN][MN];

int cap[MN][MN], par[MN];

int bfs(int s, int t) {
  fill(par, par+N+2, -1);
  par[s] = -2;
  deque<pii> Q = {{s, INT_MAX}};

  while (!Q.empty()) {
    auto [u, c] = Q.front(); Q.pop_front();
    for (int v=0; v<N+2; v++) {
      if (par[v] != -1 || cap[u][v] == 0) continue;
      par[v] = u;
      if (v == t) return min(c, cap[u][v]);
      Q.push_back({v, min(c, cap[u][v])});
    }
  }
  return 0;
}

int flow(int s, int t) {
  int f, sum = 0;
  while ((f = bfs(s, t))) {
    for (int u=t; u!=s; u=par[u]) {
      cap[par[u]][u] -= f;
      cap[u][par[u]] += f;
    }
    sum += f;
  }
  return sum;
}

int get_cost(int k) {
  int s = N, t = N+1;
  for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
      cap[i][j] = adj[i][j];

  for (int i=0; i<N; i++) {
    cap[s][i] = cap[i][t] = 0; // reset
    if (guard[k][i] == 0b11) cap[s][i] = INF;
    if (guard[k][i] == 0b00) cap[i][t] = INF;
  }

  return flow(s, t);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) for (int j=0; j<N; j++) {
    char c; cin >> c;
    adj[i][j] = c-'0';
  }

  cin >> K;
  for (int i=0, cnt; i<N; i++) {
    cin >> cnt;
    while (cnt--) { int k; cin >> k; guard[k][i] |= 1; }
  }
  for (int i=0, cnt; i<N; i++) {
    cin >> cnt;
    while (cnt--) { int k; cin >> k; guard[k][i] |= 2; }
  }

  int ans = 0;
  for (int k=0; k<K; k++) ans += get_cost(k);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
