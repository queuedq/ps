#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

const int ST = 1<<18;

struct SegTree {
  lld sum[ST*2], use[ST*2];
  bool lazy[ST*2];

  void init() {
    for (int n=ST-1; n>0; n--) sum[n] = sum[n*2] + sum[n*2+1];
  }

  void propagate(int n) {
    if (!lazy[n]) return;
    use[n] = sum[n] - use[n];
    if (n < ST) {
      lazy[n*2] ^= 1;
      lazy[n*2+1] ^= 1;
    }
    lazy[n] = 0;
  }

  void flip(int n, int nl, int nr, int l, int r) {
    propagate(n);
    if (r < nl || nr < l) return;
    if (l <= nl && nr <= r) { lazy[n] ^= 1; propagate(n); return; }
    int m = (nl+nr+1) / 2;
    flip(n*2, nl, m-1, l, r);
    flip(n*2+1, m, nr, l, r);
    use[n] = use[n*2] + use[n*2+1];
  }

  lld query() { return use[1]; }
} seg;

////////////////////////////////////////////////////////////////
const int MN = 202020;
lld N, Q, deg[MN];
lld par[MN], wgt[MN], sub[MN];
lld in[MN], out[MN], dfn, top[MN];
vector<pll> adj[MN];
lld qry[MN];

void dfs1(int u, int p) {
  for (int i=0; i<sz(adj[u]); i++) { // erase parent
    if (adj[u][i].first == p) { adj[u].erase(adj[u].begin() + i); break; }
  }

  par[u] = p;
  sub[u] = 1;

  for (int i=0; i<sz(adj[u]); i++) { // find heavy edge
    auto [v, w] = adj[u][i];
    wgt[v] = w;
    dfs1(v, u);
    sub[u] += sub[v];
    if (sub[v] > sub[adj[u][0].first]) swap(adj[u][0], adj[u][i]);
  }
}

void dfs2(int u) {
  in[u] = ++dfn;
  for (auto [v, w]: adj[u]) {
    top[v] = (v == adj[u][0].first) ? top[u] : v;
    dfs2(v);
  }
  out[u] = dfn;
}

void flip(int u) {
  while (u > 0) {
    seg.flip(1, 0, ST-1, in[top[u]], in[u]);
    u = par[top[u]];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    lld u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
    deg[u]++, deg[v]++;
  }

  cin >> Q;
  for (int q=1; q<=Q; q++) {
    lld v, w; cin >> v >> w;
    adj[v].push_back({N+q, w});
    qry[q] = v;
  }

  // HLD
  top[1] = 1;
  dfs1(1, 0);
  dfs2(1);

  // init
  for (int u=1; u<=N+Q; u++) seg.sum[ST+in[u]] = wgt[u];
  seg.init();

  int leaf = 0;
  for (int u=1; u<=N; u++) {
    if (deg[u] == 1) leaf++, flip(u);
  }

  // query
  for (int q=1; q<=Q; q++) {
    int u = N+q, v = qry[q];

    if (deg[v]++ == 1) leaf--, flip(v);
    deg[u] = 1, leaf++, flip(u);

    if (leaf % 2 == 0) cout << seg.query() << endl;
    else cout << -1 << endl;
  }

  ////////////////////////////////
  return 0;
}
