#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MV = 705;
const int ME = 123460;
int V, E, Q;
pii edge[ME];
vector<int> L, R;

struct DSU {
  vector<int> par;

  void reset() {
    par.resize(V+1);
    for (int i=1; i<=V; i++) par[i] = i;
  }

  int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
  }

  bool merge(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    par[y] = x;
    return true;
  }
} dsu;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> V >> E;
  for (int i=1; i<=E; i++) {
    int u, v; cin >> u >> v;
    edge[i] = {u, v};
  }

  dsu.reset();
  for (int i=1; i<=E; i++) {
    auto [u, v] = edge[i];
    if (dsu.merge(u, v)) L.push_back(i);
  }

  dsu.reset();
  for (int i=E; i>=1; i--) {
    auto [u, v] = edge[i];
    if (dsu.merge(u, v)) R.push_back(i);
  }

  cin >> Q;
  for (int i=0; i<Q; i++) {
    dsu.reset();
    int l, r; cin >> l >> r;
    int ans = V;

    for (auto j: L) {
      if (j >= l) break;
      ans -= dsu.merge(edge[j].first, edge[j].second);
    }
    for (auto j: R) {
      if (j <= r) break;
      ans -= dsu.merge(edge[j].first, edge[j].second);
    }

    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
