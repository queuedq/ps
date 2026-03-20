#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, par[MN];
vector<pll> adj[MN];

struct Edge {
  lld u, v, c;
  bool operator <(Edge &e) { return c < e.c; }
};
vector<Edge> E;

int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    lld u, v, c; cin >> u >> v >> c;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }

  for (int u=1; u<=N; u++) {
    par[u] = u;
    sort(all(adj[u]), [](pii a, pii b) { return a.second < b.second; });
  }

  // dist 2 edges
  for (int u=1; u<=N; u++) {
    if (sz(adj[u]) < 2) continue;
    auto [v, c] = adj[u][0];
    for (auto [w, d]: adj[u]) {
      if (v == w) continue;
      E.push_back({v, w, c+d});
    }
  }

  // dist 3 edges
  for (int u=1; u<=N; u++) for (auto [v, c]: adj[u]) {
    if (sz(adj[u]) < 2 || sz(adj[v]) < 2) continue;
    auto [w, d] = adj[u][0];
    if (w == v) tie(w, d) = adj[u][1];
    auto [x, e] = adj[v][0];
    if (x == u) tie(x, e) = adj[v][1];
    E.push_back({w, x, c+d+e});
  }

  // MST
  lld ans = 0, cnt = 0;
  sort(all(E));
  for (auto [u, v, c]: E) {
    u = find(u); v = find(v);
    if (u == v) continue;
    ans += c, cnt++;
    par[v] = u;
  }

  if (cnt == N-1) cout << ans << endl;
  else cout << -1 << endl;

  ////////////////////////////////
  return 0;
}
