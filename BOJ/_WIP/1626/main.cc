#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

using piii = pair<int, pii>;

////////////////////////////////////////////////////////////////
const int MV = 50'005;
int V, E, vst[MV], dep[MV], par[MV][18], mx[MV][18];
lld mst;
vector<pii> adj[MV];

int max_edge(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int res = 0;
  
  for (int i=17; i>=0; i--) {
    if (dep[u] - dep[v] >= 1 << i) {
      res = max(res, mx[u][i]);
      u = par[u][i];
    }
  }

  if (u == v) return res;

  for (int i=17; i>=0; i--) {
    if (par[u][i] == par[v][i]) continue;
    res = max({res, mx[u][i], mx[v][i]});
    u = par[u][i];
    v = par[v][i];
  }

  return max({res, mx[u][0], mx[v][0]});
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> V >> E;
  for (int i=0; i<E; i++) {
    int a, b, w; cin >> a >> b >> w;
    adj[a].push_back({w, b});
    adj[b].push_back({w, a});
  }

  // prim
  priority_queue<piii, vector<piii>, greater<piii>> pq;
  pq.push({0, {1, 0}});

  while (!pq.empty()) {
    auto [w, e] = pq.top(); pq.pop();
    auto [u, p] = e;
    if (vst[u]) continue;
    vst[u] = true;

    dep[u] = dep[p]+1;
    par[u][0] = p;
    mx[u][0] = w;
    mst += w;

    for (auto [x, v]: adj[u]) pq.push({x, {v, u}});
  }

  // not connected
  for (int u=2; u<=V; u++) {
    if (par[u][0] == 0) return cout << -1 << endl, 0;
  }

  // lca
  for (int j=1; j<18; j++) {
    for (int u=1; u<=V; u++) {
      par[u][j] = par[par[u][j-1]][j-1];
      mx[u][j] = max(mx[u][j-1], mx[par[u][j-1]][j-1]);
    }
  }

  // second mst
  lld ans = LLONG_MAX;

  for (int u=1; u<=V; u++) {
    for (auto [w, v]: adj[u]) {
      if (max_edge(u, v) == w) continue;
      ans = min(ans, mst + w - max_edge(u, v));
    }
  }

  if (ans < LLONG_MAX) cout << ans << endl;
  else cout << -1 << endl;

  ////////////////////////////////
  return 0;
}
