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
lld N, M, b[MN], a, x, y;
lld lever_comp[MN]; // G comp contains `a` after adding (x, y)?
lld D[MN], E[MN], F[MN], vst[MN];

struct SCC {
  int N, cn, comp[MN], vst[MN];
  vector<int> g[MN], gt[MN], ord, dag[MN];
  lld value[MN]; // component value

  void add_edge(int u, int v) {
    g[u].push_back(v);
    gt[v].push_back(u);
  }

  void dfs1(int u) {
    if (vst[u]) return;
    vst[u] = 1;
    for (auto v: g[u]) dfs1(v);
    ord.push_back(u);
  }

  void dfs2(int u, int c) {
    if (comp[u]) return;
    comp[u] = c;
    for (auto v: gt[u]) dfs2(v, c);
  }

  void scc() {
    // scc
    for (int u=1; u<=N; u++) dfs1(u);
    reverse(all(ord));
    for (auto u: ord) if (!comp[u]) dfs2(u, ++cn);

    // calc value
    for (int u=1; u<=N; u++) value[comp[u]] += b[u];

    // build dag
    for (int u=1; u<=N; u++) {
      for (auto v: g[u]) {
        int cu = comp[u], cv = comp[v];
        if (cu != cv) dag[cu].push_back(cv);
      }
      sort(all(dag[u]));
      dag[u].erase(unique(all(dag[u])), dag[u].end());
    }
  }
};

SCC G, H;

// without lever
lld dp1(int c) {
  if (vst[c]) return D[c];
  vst[c] = 1;
  for (auto d: G.dag[c]) D[c] = max(D[c], dp1(d));
  return D[c] += G.value[c];
}

// from lever room
lld dp2(int c) {
  if (vst[c]) return E[c];
  vst[c] = 1;
  for (auto d: H.dag[c]) E[c] = max(E[c], dp2(d));
  return E[c] += H.value[c];
}

// to lever room
lld dp3(int c) {
  if (vst[c]) return F[c];
  vst[c] = 1;
  if (c == G.comp[a]) return F[c] = 0;
  for (auto d: G.dag[c]) F[c] = max(F[c], dp3(d));
  return F[c] += (lever_comp[c] ? 0 : G.value[c]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) cin >> b[i];

  G.N = N;
  for (int i=1; i<=M; i++) {
    int u, v; cin >> u >> v;
    G.add_edge(u, v);
  }

  H = G;
  cin >> a >> x >> y;
  H.add_edge(x, y);
  H.add_edge(y, x);

  // scc
  G.scc();
  H.scc();

  for (int u=1; u<=N; u++) {
    if (H.comp[u] == H.comp[a]) lever_comp[G.comp[u]] = true;
  }

  // dp
  // without lever
  fill_n(vst+1, G.cn, 0);
  lld X = dp1(G.comp[1]);
  
  // from lever room
  fill_n(vst+1, H.cn, 0);
  lld Y = dp2(H.comp[a]);
  
  // to lever room
  fill_n(vst+1, G.cn, 0);
  fill_n(F+1, G.cn, -INF);
  lld Z = dp3(G.comp[1]);

  // ans
  lld ans = max(X, Y+Z);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
