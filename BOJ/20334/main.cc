#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
lld N, M, P, G, family[MN], dst[MN], vst[MN], ans;
vector<pll> adj[MN];
vector<int> dag[MN];

int dfs(int u) {
  if (vst[u]) return 0;
  vst[u] = 1;
  int res = family[u];
  for (auto v: dag[u]) res += dfs(v);
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> P >> G;
  for (int i=0; i<P; i++) {
    int v; cin >> v;
    family[v]++;
  }
  for (int i=0; i<M; i++) {
    lld u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  fill(dst+1, dst+N+1, LLONG_MAX);
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  dst[1] = 0;
  pq.push({0, 1});
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d > dst[u]) continue;
    for (auto [v, w]: adj[u]) {
      if (d+w < dst[v]) {
        dst[v] = d+w;
        pq.push({dst[v], v});
      }
    }
  }

  // build shortest path dag
  for (int u=1; u<=N; u++) {
    for (auto [v, w]: adj[u]) {
      if (dst[v] == dst[u]+w) dag[u].push_back(v);
    }
  }

  // get undiscounted cost
  lld cost = 0;
  for (int u=1; u<=N; u++) cost += dst[u] * family[u];
  ans = cost;

  // get discounts
  for (int u=1; u<=N; u++) {
    fill(vst+1, vst+N+1, 0);
    int cnt = dfs(u);
    ans = min(ans, cost - (dst[u] - G) * cnt);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
