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
const int MN = 101010;
lld N, M, dist[MN], sum;
vector<pii> adj[MN];
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////
 
  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
 
  // dijkstra
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  fill(dist, dist+N+1, INF);
  pq.push({0, 0});
  dist[0] = 0;
 
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (dist[u] != d) continue;
    for (auto [v, w]: adj[u]) {
      if (d+w >= dist[v]) continue;
      dist[v] = d+w;
      pq.push({dist[v], v});
    }
  }
 
  // get ans
  for (int u=1; u<=N; u++) {
    lld best = 0;
    for (auto [v, w]: adj[u]) {
      if (dist[v] + w == dist[u]) best = max(best, (lld)w);
    }
    sum += best;
  }
 
  cout << M - N << " " << sum << endl;
 
  ////////////////////////////////
  return 0;
}
