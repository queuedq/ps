#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, K, par[MAXN][20], mn[MAXN][20], mx[MAXN][20], dep[MAXN];
vector<pii> adj[MAXN];

void dfs(int u, int p, int w, int d) {
  par[u][0] = p;
  mn[u][0] = w;
  mx[u][0] = w;
  dep[u] = d;
  for (auto [v, c]: adj[u]) {
    if (v == p) continue;
    dfs(v, u, c, d+1);
  }
}

pii lca(int u, int v) {
  int lo = 1e9, hi = 0;

  if (dep[u] < dep[v]) swap(u, v);

  for (int k=19; k>=0; k--) {
    if (1 << k <= dep[u] - dep[v]) {
      lo = min(lo, mn[u][k]);
      hi = max(hi, mx[u][k]);
      u = par[u][k];
    }
  }

  if (u == v) return {lo, hi};

  for (int k=19; k>=0; k--) {
    if (par[u][k] == par[v][k]) continue;
    lo = min({lo, mn[u][k], mn[v][k]});
    hi = max({hi, mx[u][k], mx[v][k]});
    u = par[u][k];
    v = par[v][k];
  }

  lo = min({lo, mn[u][0], mn[v][0]});
  hi = max({hi, mx[u][0], mx[v][0]});
  return {lo, hi};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int a, b, c; cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }

  dfs(1, 0, 0, 0);

  for (int k=1; k<20; k++) {
    for (int i=1; i<=N; i++) {
      par[i][k] = par[par[i][k-1]][k-1];
      mn[i][k] = min(mn[i][k-1], mn[par[i][k-1]][k-1]);
      mx[i][k] = max(mx[i][k-1], mx[par[i][k-1]][k-1]);
    }
  }

  cin >> K;
  for (int i=0; i<K; i++) {
    int u, v; cin >> u >> v;
    auto [lo, hi] = lca(u, v);
    cout << lo << " " << hi << endl;
  }

  ////////////////////////////////
  return 0;
}
