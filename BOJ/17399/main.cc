#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
vector<int> adj[MN];
int N, Q, par[MN][20], dep[MN];

void dfs(int u, int p, int d) {
  par[u][0] = p;
  dep[u] = d;
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u, d+1);
  }
}

int lca(int u, int v) {
  // make same depth
  if (dep[u] < dep[v]) swap(u, v);
  for (int k=19; k>=0; k--) {
    if (dep[par[u][k]] >= dep[v]) u = par[u][k];
  }

  // binary lifting
  if (u == v) return u;
  for (int k=19; k>=0; k--) {
    if (par[u][k] != par[v][k]) {
      u = par[u][k];
      v = par[v][k];
    }
  }
  return par[u][0];
}

int dist(int u, int v) {
  int l = lca(u, v);
  return dep[u] + dep[v] - dep[l]*2;
}

int ancestor(int u, int d) {
  for (int k=19; k>=0; k--) {
    if (d>>k & 1) u = par[u][k];
  }
  return u;
}

int node_at_dist(int u, int v, int d) {
  int l = lca(u, v);
  int p = dep[u] + dep[v] - dep[l]*2;
  if (d <= dep[u]-dep[l]) return ancestor(u, d);
  else return ancestor(v, p-d);
}

int circumcenter(int a, int b, int c) {
  // find midpoint m of a, b
  int p = dist(a, b);
  if (p%2 != 0) return -1;
  int m = node_at_dist(a, b, p/2);

  // find circumcenter in between c and m
  int q = dist(c, m);
  if (q < p/2) return -1;

  int diam = q + p/2;
  if (diam%2 != 0) return -1;
  int r = diam/2;

  int center = node_at_dist(c, m, r);

  // check same dist
  int ra = dist(center, a);
  int rb = dist(center, b);
  if (ra == r && rb == r) return center;
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // lca preprocessing
  dfs(1, 0, 1);

  for (int k=1; k<20; k++) {
    for (int i=1; i<=N; i++) {
      par[i][k] = par[par[i][k-1]][k-1];
    }
  }

  // queries
  cin >> Q;
  for (int q=0; q<Q; q++) {
    int a, b, c; cin >> a >> b >> c;
    cout << circumcenter(a, b, c) << endl;
  }

  ////////////////////////////////
  return 0;
}
