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
lld N, M, X;

struct Edge { lld v, w, p; };
vector<Edge> adj[MN];

lld solve(lld red) {
  lld blue = X - red;
  vector<lld> dst(N+1, LLONG_MAX);
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  dst[1] = 0;
  pq.push({0, 1});

  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d > dst[u]) continue;
    if (u == N) return d;

    for (auto [v, w, p]: adj[u]) {
      if (p == 1) w += red;
      else if (p == 2) w += blue;

      if (d+w >= dst[v]) continue;
      dst[v] = d+w;
      pq.push({dst[v], v});
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> X;
  for (int i=0; i<M; i++) {
    int u, v, w, p; cin >> u >> v >> w >> p;
    adj[u].push_back({v, w, p});
    adj[v].push_back({u, w, p});
  }

  lld l = -1, r = X;
  while (l+1 < r) {
    lld m = (l+r)/2;
    if (solve(m) >= solve(m+1)) r = m;
    else l = m;
  }

  cout << solve(r) << endl;

  ////////////////////////////////
  return 0;
}
