#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int XN = 101010;
const int XM = 303030;
lld N, M, sum, dsu[XN], par[XN], dep[XN], cost[XN];
lld mst[XM], ans[XM];
vector<pll> adj[XN];

struct Edge {
  lld u, v, w, i;
  bool operator <(const Edge &e) const { return w < e.w; }
};
vector<Edge> edge;

int find(int x) {
  return dsu[x] = x == dsu[x] ? x : find(dsu[x]);
}

bool merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return false;
  dsu[y] = x;
  return true;
}

void dfs1(int u, int p, int d) {
  dep[u] = d, par[u] = p;
  for (auto [v, w]: adj[u]) {
    if (v == p) continue;
    dfs1(v, u, d+1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    lld u, v, w; cin >> u >> v >> w;
    edge.push_back({u, v, w, i});
  }
  sort(all(edge));
  iota(dsu, dsu+N+1, 0);

  for (auto [u, v, w, i]: edge) {
    if (!merge(u, v)) continue;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
    sum += w;
    mst[i] = 1;
  }

  dfs1(1, 0, 0);
  iota(dsu, dsu+N+1, 0);

  for (auto [u, v, w, i]: edge) {
    if (mst[i]) continue;
    while (u != v) {
      int du = dep[u], dv = dep[v];
      if (du >= dv) {
        if (cost[u] == 0) cost[u] = w;
        if (dsu[u] == u) dsu[u] = par[u];
        u = find(u);
      }
      if (du <= dv) {
        if (cost[v] == 0) cost[v] = w;
        if (dsu[v] == v) dsu[v] = par[v];
        v = find(v);
      }
    }
  }

  for (auto [u, v, w, i]: edge) {
    if (!mst[i]) ans[i] = sum;
    else {
      lld c = par[u] == v ? cost[u] : cost[v];
      ans[i] = c ? sum - w + c : -1;
    }
  }

  for (int i=0; i<M; i++) cout << ans[i] << endl;

  ////////////////////////////////
  return 0;
}
