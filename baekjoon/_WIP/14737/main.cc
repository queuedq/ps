#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct scc {
  int n;
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
    for (int i=0; i<n; ++i) {
      if (!vst[i]) dfs1(i);
    }
    reverse(ord.begin(), ord.end());

    comp.assign(n, -1);
    for (int i=0, j=0; i<n; ++i) {
      int u = ord[i];
      if (comp[u] == -1) dfs2(u, j++);
    }
  }
};

struct two_sat: scc {
  // g: 0-based, (even: x, odd: !x)
  set<pii> clauses;
  vector<bool> ans;

  two_sat(int var): scc(var*2) { }

  void add_clause(int a, int b) {
    if (clauses.count({a, b})) return;
    clauses.insert({a, b}); clauses.insert({b, a});
    add_edge(a^1, b); add_edge(b^1, a);
  }

  bool solve() {
    scc::solve();

    ans.assign(n/2, false);
    for (int i=0; i<n/2; i++) {
      if (comp[i*2] == comp[i*2+1]) return false;
      ans[i] = comp[i*2] > comp[i*2+1];
    }
    return true;
  }
};

////////////////////////////////////////////////////////////////
const int MH = 55;
int H, W;
char level[MH][MH];

inline int node(int i, int j, int k) { return ((i-1)*W + (j-1))*2 + k; }
inline bool blank(int i, int j) { return 1<=i && i<=H && 1<=j && j<=W && level[i][j] != '#'; }

void dfs(int u, vector<vector<int>> &graph, vector<bool> &vst) {
  if (vst[u]) return;
  vst[u] = true;
  for (auto v: graph[u]) dfs(v, graph, vst);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> H >> W;
  for (int i=1; i<=H; i++) {
    for (int j=1; j<=W; j++) cin >> level[i][j];
  }

  // SCC
  scc G(H*W*2);

  for (int i=1; i<=H; i++) {
    for (int j=1; j<=W; j++) {
      int v = node(i, j, 0), h = node(i, j, 1);
      int u = node(i-1, j, 0), d = node(i+1, j, 0);
      int l = node(i, j-1, 1), r = node(i, j+1, 1);

      if (blank(i-1, j)) G.add_edge(v, u);
      if (blank(i+1, j)) G.add_edge(v, d);
      if (blank(i, j-1)) G.add_edge(h, l);
      if (blank(i, j+1)) G.add_edge(h, r);
      if (!blank(i-1, j) || !blank(i+1, j)) G.add_edge(v, h);
      if (!blank(i, j-1) || !blank(i, j+1)) G.add_edge(h, v);
    }
  }

  G.solve();

  // 2-SAT
  two_sat T(H*W*2);

  for (int i=1; i<=H; i++) {
    for (int j=1; j<=W; j++) {
      int cell = level[i][j];
      if (cell == '#' || cell == '.') continue;
      T.add_clause(G.comp[node(i, j, 0)]*2, G.comp[node(i, j, 1)]*2);

      for (int k: {0, 1}) {
        int u = node(i, j, k);

        vector<bool> vf(H*W*2), vb(H*W*2);
        dfs(u, G.g, vf);
        if (cell == '*') dfs(u, G.gt, vb);

        for (int v=0; v<H*W*2; v++) {
          if (!vf[v] && !vb[v]) T.add_clause(G.comp[u]*2+1, G.comp[v]*2+1);
        }
      }
    }
  }

  cout << (T.solve() ? "YES" : "NO") << endl;

  ////////////////////////////////
  return 0;
}
