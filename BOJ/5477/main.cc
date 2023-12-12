#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int _N = 1010;
const int _M = 5050;
int N, M, par[_N], dep[_N], tot;
vector<int> adj[_N]; // tree
int D[_N][1<<10], E[_N][_M];
// D[u][m]: avail edge set m, max cost
// E[u][e]: use path e, max cost

struct Edge { int u, v, w; };
vector<Edge> edges;
int on_path[_N][_M];
vector<int> paths[_N]; // paths meeting at here

void dfs(int u, int p, int d) {
  par[u] = p, dep[u] = d;
  for (auto v: adj[u])
    if (v != p) dfs(v, u, d+1);
}

void get_path(int e) {
  auto [u, v, w] = edges[e];
  // lca
  if (dep[u] < dep[v]) swap(u, v);
  while (dep[u] > dep[v]) on_path[u][e] = 1, u = par[u];
  while (u != v) on_path[u][e] = on_path[v][e] = 1, u = par[u], v = par[v];
  paths[u].push_back(e);
}

void dp(int u) {
  for (auto v: adj[u]) dp(v);
  int deg = sz(adj[u]);

  // don't add path
  for (int m=0; m<1<<deg; m++) {
    for (int i=0; i<deg; i++) {
      int v = adj[u][i];
      if (m>>i & 1) D[u][m] += D[v][(1<<sz(adj[v])) - 1];
    }
  }

  // add complete path
  for (auto e: paths[u]) {
    int cost = 0, mask = 0;
    for (int i=0; i<deg; i++) {
      int v = adj[u][i];
      if (on_path[v][e]) cost += E[v][e], mask |= 1<<i;
    }

    for (int m=0; m<1<<deg; m++) {
      if ((m & mask) != mask) continue;
      D[u][m] = max(D[u][m], D[u][m^mask] + cost + edges[e].w);
    }
  }

  // add partial path
  for (int e=0; e<sz(edges); e++) {
    if (!on_path[u][e]) continue;

    int cost = 0, mask = (1<<deg) - 1;
    for (int i=0; i<deg; i++) {
      int v = adj[u][i];
      if (on_path[v][e]) cost += E[v][e], mask ^= 1<<i;
    }
    E[u][e] = cost + D[u][mask];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=M; i++) {
    int u, v, w; cin >> u >> v >> w;
    if (w == 0) adj[u].push_back(v), adj[v].push_back(u);
    else edges.push_back({u, v, w}), tot += w;
  }

  // dfs
  dfs(1, 0, 0);
  for (int u=2; u<=N; u++)
    adj[u].erase(find(all(adj[u]), par[u]));

  // get paths
  for (int e=0; e<sz(edges); e++) {
    auto [u, v, w] = edges[e];
    if ((dep[u]&1) != (dep[v]&1)) continue; // even cycle
    get_path(e);
  }

  // dp
  dp(1);
  int mask = (1<<sz(adj[1])) - 1;
  cout << tot - D[1][mask] << endl;

  ////////////////////////////////
  return 0;
}
