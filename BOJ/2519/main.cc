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

struct Point {
  lld x, y;
  Point(): x(0), y(0) {}
  Point(lld x, lld y): x(x), y(y) {}

  bool operator ==(Point a) const { return x == a.x && y == a.y; }
  bool operator !=(Point a) const { return !(*this == a); }
  bool operator <(Point a) const { return pair(x, y) < pair(a.x, a.y); }
  Point operator +(Point a) const { return {x+a.x, y+a.y}; }
  Point operator -(Point a) const { return {x-a.x, y-a.y}; }
  Point operator *(lld c) const { return {x*c, y*c}; }
  Point operator /(lld c) const { return {x/c, y/c}; }
  lld operator *(Point a) const { return x*a.x + y*a.y; }
};

ostream& operator <<(ostream& os, Point a) { return os << "(" << a.x << ", " << a.y << ")"; }

lld cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }
lld ccw(Point a, Point b, Point c) { return cross(b-a, c-a) > 0; }

////////////////////////////////////////////////////////////////
const int MN = 1005;
int N;

struct Line {
  Point p, q; int i, j;
  bool intersect(Line L) {
    return (ccw(p, q, L.p) ^ ccw(p, q, L.q)) && (ccw(L.p, L.q, p) ^ ccw(L.p, L.q, q));
  }
};
Line L[MN*3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    for (int j=0; j<3; j++) {
      int x, y, z, w; cin >> x >> y >> z >> w;
      L[i*3+j] = {{x, y}, {z, w}, i, j};
    }
  }

  two_sat S(N*3);

  for (int i=0; i<N; i++) {
    S.add_clause(i*6+1, i*6+3);
    S.add_clause(i*6+3, i*6+5);
    S.add_clause(i*6+5, i*6+1);
  }

  for (int i=0; i<N*3; i++) {
    for (int j=0; j<i; j++) {
      if (L[i].intersect(L[j])) S.add_clause(i*2, j*2);
    }
  }

  bool ok = S.solve();
  if (!ok) return cout << -1, 0;

  vector<int> ans;
  for (int i=0; i<N*3; i++) {
    if (S.ans[i]) ans.push_back(i+1);
  }
  cout << ans.size() << endl;
  for (auto a: ans) cout << a << " ";

  ////////////////////////////////
  return 0;
}
