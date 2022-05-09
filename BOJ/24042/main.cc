#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
const lld INF = 1e18;
lld N, M, dst[MN];
vector<pll> adj[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }
  fill(dst+1, dst+N+1, INF);

  priority_queue<pll, vector<pll>, greater<pll>> pq;
  pq.push({0, 1});
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d >= dst[u]) continue;
    dst[u] = d;
    if (u == N) break;
    for (auto [v, i]: adj[u]) {
      lld dd = d/M*M + i+1;
      if (d%M > i) dd += M;
      if (dd >= dst[v]) continue; 
      pq.push({dd, v});
    }
  }

  cout << dst[N] << endl;

  ////////////////////////////////
  return 0;
}
