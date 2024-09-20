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

struct Line {
  mutable lld a, b;
  mutable double p; // right intersection
  double inter(const Line &L) const {
    if (a == L.a) return p = (b > L.b) ? INF : -INF;
    return p = (double)(L.b-b) / (a-L.a);
  }
  bool operator<(const Line &L) const { return a < L.a; }
  bool operator<(lld x) const { return p < x; }
};

struct LineContainer: multiset<Line, less<>> {
  lld offset;

  bool bad(iterator x) { // x is under prev(x) and next(x)
    if (x == begin() || next(x) == end()) return 0;
    return !(prev(x)->p < x->p);
  }

  iterator erase_update(iterator x) {
    if (x != begin()) {
      auto l = prev(x), r = next(x);
      if (r == end()) l->p = INF; else l->inter(*r);
    } 
    return erase(x);
  }

  void insert_line(lld a, lld b) {
    auto x = insert({a, b - offset, INF});
    if (x != begin()) prev(x)->inter(*x);
    if (next(x) != end()) x->inter(*next(x));

    if (bad(x)) x = erase_update(x);
    else {
      while (next(x) != end() && bad(next(x))) erase_update(next(x));
      while (x != begin() && bad(prev(x))) erase_update(prev(x));
    }
  }

  void add_all(lld x) { offset += x; }

  lld query(lld x) {
    auto l = lower_bound(x);
    if (l == end()) return -INF;
    return l->a * x + l->b + offset;
  }
};

////////////////////////////////////////////////////////////////
const int MN = 50505;
int N;
vector<int> adj[MN];
LineContainer G[MN];

// future cost (at depth x) = C + (d-x)^2 = C + d^2 - 2dt + x^2
// a (slope) = 2d
// b = -C - d^2
// (negated b/c we need min hull)

lld get_cost(int u, lld d) { return -G[u].query(d) + d*d; }

void dfs(int u, int p, lld d) {
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u, d+1);

    if (sz(G[u]) < sz(G[v])) swap(G[u], G[v]);
    if (sz(G[v]) == 0) continue; // first child

    // get costs
    lld u_cost = get_cost(u, d); // close u
    lld v_cost = get_cost(v, d); // close v
    lld uv_cost = INF; // close both

    for (auto &L: G[v]) { // matching in subtree v
      lld e = L.a / 2; // v path's starting depth
      lld cost = get_cost(u, d - (e-d)); // calc cost using u path
      cost += -(L.b + G[v].offset) - e*e; // and add v path's remaining C
      uv_cost = min(uv_cost, cost);
    }

    G[u].add_all(-v_cost); // close v
    for (auto &L: G[v]) { // close u
      G[u].insert_line(L.a, L.b + G[v].offset - u_cost);
    }
    G[u].insert_line(d*2, -uv_cost - d*d); // close both

    G[v].clear();
  }

  if (sz(G[u]) == 0) G[u].insert_line(d*2, -d*d); // start path on leaf
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int r = 1;
  while (sz(adj[r]) > 1) r++; // leaf as root

  dfs(r, 0, 0);
  cout << get_cost(r, 0) << endl;

  ////////////////////////////////
  return 0;
}
