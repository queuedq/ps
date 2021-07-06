#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct scc {
  int n, scc_cnt;
  vector<vector<int>> g, gt;
  vector<bool> vst;
  vector<int> ord, comp;

  scc(int n): n(n) { g.resize(n); gt.resize(n); }

  void add_edge(int a, int b) { g[a].push_back(b); gt[b].push_back(a); }

  void dfs1(int u) {
    if (vst[u]) return;
    vst[u] = true;
    for (int v: g[u]) dfs1(v);
    ord.push_back(u);
  }

  void dfs2(int u, int cl) {
    comp[u] = cl;
    for (int v: gt[u]) {
      if (comp[v] == -1) dfs2(v, cl);
    }
  }

  void solve() {
    vst.assign(n, false);
    for (int i=0; i<n; i++) {
      if (!vst[i]) dfs1(i);
    }
    reverse(ord.begin(), ord.end());

    comp.assign(n, -1);
    scc_cnt = 0;
    for (int i=0; i<n; i++) {
      int u = ord[i];
      if (comp[u] == -1) dfs2(u, scc_cnt++);
    }
  }
};

////////////////////////////////////////////////////////////////
const int MN = 20202;
int N, M, in[MN], out[MN];

int solve() {
  cin >> N >> M;
  vector<pii> edges;
  scc S(N);
  for (int i=0; i<M; i++) {
    int a, b; cin >> a >> b;
    edges.push_back({a-1, b-1});
    S.add_edge(a-1, b-1);
  }

  S.solve();
  if (S.scc_cnt == 1) return 0;

  fill(in, in+S.scc_cnt, 0);
  fill(out, out+S.scc_cnt, 0);
  for (auto [a, b]: edges) {
    if (S.comp[a] != S.comp[b]) {
      in[S.comp[a]]++;
      out[S.comp[b]]++;
    }
  }
  
  int in0 = 0, out0 = 0;
  for (int i=0; i<S.scc_cnt; i++) {
    if (in[i] == 0) in0++;
    if (out[i] == 0) out0++;
  }

  return max(in0, out0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) cout << solve() << endl;

  ////////////////////////////////
  return 0;
}
