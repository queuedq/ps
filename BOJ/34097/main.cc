#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 1e18;
const int MN = 101010;

int N, M, S, E, K;
vector<int> adj[MN], tree[MN];

int par[MN]; // union-find
lld D[MN]; // dist to parent
int mem_prv[MN]; // previous node in memory

pll find(int u) {
  if (par[u] == u) return {u, 0};
  auto [p, d] = find(par[u]);
  // compress + update D[u]
  par[u] = p;
  D[u] = min(D[u]+d, INF);
  return {p, D[u]};
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> S >> E;
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cin >> K;
  for (int i=0, u=-1; i<K; i++) {
    int v; cin >> v;
    mem_prv[v] = u;
    u = v;
  }

  // union find + dp
  for (int u=1; u<=N; u++) par[u] = u;
  lld ans = 0;

  for (int u=1; u<=N; u++) {
    // dp
    for (auto v: adj[u]) if (v <= u) {
      auto [m, d] = find(v);
      D[m] = min(max(D[m], d+1), INF);
    }

    // merge components
    for (auto v: adj[u]) if (v <= u) {
      auto [m, d] = find(v);
      par[m] = u;
    }

    // query on memory path
    int t = mem_prv[u];

    if (t == -1) { // first memory
      auto [m, d] = find(S);
      if (m != u) return cout << "impossible" << endl, 0;
      ans = min(ans + d, INF);
    } else if (t) { // t > u
      lld max_d = 0;
      for (auto v: adj[t]) {
        auto [m, d] = find(v);
        if (m == u) max_d = max(max_d, d+1);
      }
      if (max_d == 0) return cout << "impossible" << endl, 0;
      ans = min(ans + max_d, INF);
    }
  }

  // print ans
  if (ans == INF) cout << "eternity" << endl;
  else cout << ans << endl;

  ////////////////////////////////
  return 0;
}
