#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505050;
int N, Q;
vector<int> adj[MN];
int par[MN][20], dep[MN], dfn[MN], id;

void dfs(int u, int p) {
  par[u][0] = p;
  dep[u] = dep[p]+1;
  dfn[u] = ++id;
  for (auto v: adj[u]) {
    dfs(v, u);
  }
}

int lca(int u, int v) {
  if (u == v) return u;
  if (dfn[u] > dfn[v]) swap(u, v);
  for (int k=19; k>=0; k--) {
    if (dfn[u] < dfn[par[v][k]]) v = par[v][k];
  }
  return par[v][0];
}

struct CompressedTree {
  vector<pii> adj[MN];
  lld cnt[MN], D[MN];

  void add_edge(int u, int v, int d) {
    adj[u].push_back({v, d});
  }

  lld dp(int u) {
    for (auto [v, d]: adj[u]) {
      dp(v);
      D[u] += D[v] + cnt[u] * cnt[v] * dep[u];
      cnt[u] += cnt[v];
    }
    return D[u];
  }

  void reset(vector<int> &nodes) {
    for (auto u: nodes) {
      adj[u].clear();
      cnt[u] = D[u] = 0;
    }
  }
} T;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> Q;
  for (int u=2; u<=N; u++) {
    int p; cin >> p;
    adj[p].push_back(u);
  }

  // prepare lca
  id = 0, dep[0] = -1;
  dfs(1, 0);
  for (int k=1; k<20; k++)
    for (int u=1; u<=N; u++)
      par[u][k] = par[par[u][k-1]][k-1];
  
  // query
  for (int q=0; q<Q; q++) {
    int k; cin >> k;
    vector<int> U(k);
    for (int i=0; i<k; i++) cin >> U[i];
    vector<int> V = U; // compressed tree nodes

    // tree compression
    sort(all(U), [](int a, int b) { return dfn[a] < dfn[b]; });
    for (int i=0; i<k-1; i++) V.push_back(lca(U[i], U[i+1]));

    sort(all(V), [](int a, int b) { return dfn[a] < dfn[b]; });
    V.erase(unique(all(V)), V.end());

    for (int i=0; i<sz(V)-1; i++) {
      int p = lca(V[i], V[i+1]);
      T.add_edge(p, V[i+1], dep[V[i+1]] - dep[p]);
    }

    // dp
    for (auto u: U) T.cnt[u]++;
    cout << T.dp(V[0]) << endl;;

    // reset
    T.reset(V);
  }

  ////////////////////////////////
  return 0;
}
