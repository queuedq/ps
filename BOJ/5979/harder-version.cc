#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
// 잘못 읽고 리프를 골라서 갈림길까지 간선을 태우는 버전의 문제를 풀었음....
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
lld N, sub[MN];
vector<int> adj[MN];
LineContainer G[MN][2]; // G[u][m]: m leaf matchings in subtree u

// future cost (at depth x) = C + (d-x)^2 = C + d^2 - 2dt + x^2
// a (slope) = 2d
// b = -C - d^2
// (negated b/c we need min hull)

lld get_cost(int u, int m, lld d) { return -G[u][m].query(d) + d*d; }

void dfs(int u, int p, lld d) {
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u, d+1);

    if (sub[u] < sub[v]) swap(G[u][0], G[v][0]), swap(G[u][1], G[v][1]);
    sub[u] += sub[v];
    if (sub[u] == sub[v]) continue; // first child

    // get costs
    lld u_cost = get_cost(u, 0, d); // close u
    lld v_cost = get_cost(v, 0, d); // close v
    lld uv_cost = INF; // close both

    for (auto &L: G[v][1]) { // matching in subtree v
      lld e = L.a / 2; // v path's starting depth
      lld cost = get_cost(u, 0, d - (e-d)); // calc cost using u path
      cost += -L.b - e*e; // and add v path's remaining C
      uv_cost = min(uv_cost, cost);
    }

    for (auto &L: G[v][0]) { // matching not in subtree v
      lld e = L.a / 2;
      lld cost = min(get_cost(u, 0, d - (e-d)), get_cost(u, 1, d - (e-d)));
      cost += -L.b - e*e;
      uv_cost = min(uv_cost, cost);
    }

    // close v
    G[u][0].add_all(-v_cost);
    G[u][1].add_all(-v_cost);

    // close u
    for (auto &L: G[v][0]) G[u][0].insert_line(L.a, L.b + G[v][0].offset - u_cost);
    for (auto &L: G[v][1]) G[u][1].insert_line(L.a, L.b + G[v][1].offset - u_cost);

    // close both
    G[u][1].insert_line(d*2, -uv_cost - d*d);

    // clear
    G[v][0].clear();
    G[v][1].clear();
  }

  if (sz(G[u][0]) == 0) { // start path on leaf
    sub[u] = 1;
    G[u][0].insert_line(d*2, -d*d);
  }
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
  cout << get_cost(r, 1, 0) << endl;

  ////////////////////////////////
  return 0;
}
