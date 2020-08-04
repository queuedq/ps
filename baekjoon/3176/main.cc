#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, K;
vector<pii> adj[MAXN];
pair<int, pii> parent[MAXN][20];
int depth[MAXN];

void dfs(int u, int p, int d) {
  depth[u] = d;
  for (auto [v, w]: adj[u]) {
    if (v == p) continue;
    parent[v][0] = {u, {w, w}};
    dfs(v, u, d+1);
  }
}

void construct() {
  for (int d=1; d<20; d++) {
    for (int i=1; i<=N; i++) {
      auto [p, w] = parent[i][d-1];
      auto [pp, ww] = parent[p][d-1];
      parent[i][d] = {pp, {min(w.first, ww.first), max(w.second, ww.second)}};
    }
  }
}

pair<int, pii> lca(int u, int v) {
  int mn = 1e9, mx = 0;

  if (depth[u] < depth[v]) swap(u, v);

  for (int b=19; b>=0; b--) {
    if ((1 << b) <= depth[u] - depth[v]) {
      mn = min(mn, parent[u][b].second.first);
      mx = max(mx, parent[u][b].second.second);
      u = parent[u][b].first;
    }
  }
  assert(depth[u] == depth[v]);

  for (int b=19; b>=0; b--) {
    if (parent[u][b].first == parent[v][b].first) continue;
    mn = min({mn, parent[u][b].second.first, parent[v][b].second.first});
    mx = max({mx, parent[u][b].second.second, parent[v][b].second.second});
    u = parent[u][b].first;
    v = parent[v][b].first;
  }

  if (u != v) {
    mn = min({mn, parent[u][0].second.first, parent[v][0].second.first});
    mx = max({mx, parent[u][0].second.second, parent[v][0].second.second});
    u = parent[u][0].first;
    v = parent[v][0].first;
  }

  return {u, {mn, mx}};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int a, b, w; cin >> a >> b >> w;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }

  dfs(1, 0, 0);
  construct();

  cin >> K;
  for (int i=0; i<K; i++) {
    int u, v; cin >> u >> v;
    auto [p, w] = lca(u, v);
    cout << w.first << " " << w.second << endl;
  }

  ////////////////////////////////
  return 0;
}
