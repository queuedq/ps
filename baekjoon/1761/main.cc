#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 40'005;
int N, M, dep[MN], par[MN][20], dst[MN][20];
vector<pii> adj[MN];

void dfs(int u, int p, int w, int d) {
  dep[u] = d;
  par[u][0] = p;
  dst[u][0] = w;
  for (auto [v, x]: adj[u]) {
    if (v == p) continue;
    dfs(v, u, x, d+1);
  }
}

int lca(int u, int v) {
  int d = 0;
  if (dep[u] < dep[v]) swap(u, v);
  for (int k=19; k>=0; k--) {
    if (dep[par[u][k]] < dep[v]) continue;
    d += dst[u][k];
    u = par[u][k];
  }
  if (u == v) return d;
  for (int k=19; k>=0; k--) {
    if (par[u][k] == par[v][k]) continue;
    d += dst[u][k] + dst[v][k];
    u = par[u][k];
    v = par[v][k];
  }
  return d + dst[u][0] + dst[v][0];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  dfs(1, 0, 0, 1);

  for (int k=1; k<20; k++) {
    for (int i=1; i<=N; i++) {
      par[i][k] = par[par[i][k-1]][k-1];
      dst[i][k] = dst[i][k-1] + dst[par[i][k-1]][k-1];
    }
  }
  
  cin >> M;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    cout << lca(u, v) << endl;
  }

  ////////////////////////////////
  return 0;
}
