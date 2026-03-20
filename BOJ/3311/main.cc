#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9;
const int MN = 303030;

int N, M, A, B;
pii P[MN];

struct SCC {
  int N;
  vector<int> G[MN], Gt[MN], ord, dag[MN];
  int vst[MN], comp[MN], num_comp = 0;

  void add_edge(int u, int v) {
    G[u].push_back(v);
    Gt[v].push_back(u);
  }

  void dfs1(int u) {
    if (vst[u]) return;
    vst[u] = 1;
    for (auto v: G[u]) dfs1(v);
    ord.push_back(u);
  }

  void dfs2(int u, int c) {
    if (comp[u]) return;
    comp[u] = c;
    for (auto v: Gt[u]) dfs2(v, c);
  }

  void scc() {
    // scc
    for (int u=1; u<=N; u++) dfs1(u);
    reverse(all(ord));
    for (auto u: ord) dfs2(u, ++num_comp);

    // build DAG
    for (int u=1; u<=N; u++) {
      int cu = comp[u];
      for (auto v: G[u]) {
        int cv = comp[v];
        if (cu != cv) dag[cu].push_back(cv);
      }
      sort(all(dag[cu]));
      dag[cu].erase(unique(all(dag[cu])), dag[cu].end());
    }
  }
};

SCC S;
vector<pii> west, east;
int vst[MN], lo[MN], hi[MN];

void mark_reachable(vector<int> G[], int u) {
  if (vst[u]) return;
  vst[u] = 1;
  for (auto v: G[u]) mark_reachable(G, v);
}

void dp(vector<int> dag[], int u) {
  if (vst[u]) return;
  vst[u] = 1;
  for (auto v: dag[u]) {
    dp(dag, v);
    lo[u] = min(lo[u], lo[v]);
    hi[u] = max(hi[u], hi[v]);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> A >> B;
  for (int u=1; u<=N; u++) {
    int x, y; cin >> x >> y;
    P[u] = {x, y};
  }

  S.N = N;
  for (int i=0; i<M; i++) {
    int u, v, k; cin >> u >> v >> k;
    S.add_edge(u, v);
    if (k == 2) S.add_edge(v, u);
  }

  S.scc();

  // collect west and (reachable) east points
  fill_n(vst+1, N, 0);
  for (int u=1; u<=N; u++) {
    auto [x, y] = P[u];
    if (x == 0) west.push_back({y, u}), mark_reachable(S.G, u);
  }
  sort(all(west)); reverse(all(west));

  for (int u=1; u<=N; u++) {
    auto [x, y] = P[u];
    if (x == A && vst[u]) east.push_back({y, u});
  }
  sort(all(east));

  // DP
  for (int c=1; c<=S.num_comp; c++) lo[c] = INF, hi[c] = -INF;
  for (int i=0; i<sz(east); i++) {
    auto [y, u] = east[i];
    lo[S.comp[u]] = min(lo[S.comp[u]], i);
    hi[S.comp[u]] = max(hi[S.comp[u]], i);
  }

  fill_n(vst+1, N, 0);
  for (int c=1; c<=S.num_comp; c++) dp(S.dag, c);

  // print ans
  for (auto [y, u]: west) {
    int c = S.comp[u];
    if (lo[c] > hi[c]) cout << 0 << endl;
    else cout << hi[c] - lo[c] + 1 << endl;
  }

  ////////////////////////////////
  return 0;
}
