#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct two_sat {
  int n; // number of variables, not number of nodes
  vector<vector<int>> g, gt; // 0-based, even: x, odd: !x / gt = transpose of g
  vector<bool> vst;
  vector<int> ord, comp;
  vector<bool> ans;

  two_sat(int n): n(n) { g.resize(n*2); gt.resize(n*2); }

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

  void add_clause(int a, int b) { // add a|b
    g[a^1].push_back(b); gt[a].push_back(b^1);
    g[b^1].push_back(a); gt[b].push_back(a^1);
  }

  bool solve() {
    // topo-sort
    vst.assign(n*2, false);
    for (int i=0; i<n*2; ++i) {
      if (!vst[i]) dfs1(i);
    }
    reverse(ord.begin(), ord.end());

    // scc
    comp.assign(n*2, -1);
    for (int i=0, j=0; i<n*2; ++i) {
      int u = ord[i];
      if (comp[u] == -1) dfs2(u, j++);
    }

    // solve
    ans.assign(n, false);
    for (int i=0; i<n; i++) {
      if (comp[i*2] == comp[i*2+1]) return false;
      ans[i] = comp[i*2] > comp[i*2+1];
    }
    return true;
  }
};

////////////////////////////////////////////////////////////////
const int MN = 10'005;
int N, M;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  two_sat S(N);
  for (int i=0; i<M; i++) {
    int a, b; cin >> a >> b;
    if (a > 0) a = a*2-2;
    else a = -a*2-1;
    if (b > 0) b = b*2-2;
    else b = -b*2-1;
    S.add_clause(a, b);
  }

  cout << S.solve() << endl;

  ////////////////////////////////
  return 0;
}
