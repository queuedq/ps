#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 10101;
lld N, M, A[MN], D[MN], E[MN];
vector<pll> adj[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int u=0; u<N; u++) cin >> A[u];
  for (int i=0; i<M; i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  priority_queue<pll, vector<pll>, greater<pll>> pq;
  for (int u=0; u<N; u++) {
    D[u] = A[u];
    E[u] = u;
    pq.push({A[u], u});
  }
  
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (D[u] != d) continue;
    for (auto [v, w]: adj[u]) {
      if (d+w < D[v]) {
        D[v] = d+w;
        E[v] = E[u];
        pq.push({d+w, v});
      }
    }
  }

  lld ans = LLONG_MAX;
  for (int u=0; u<N; u++) {
    if (E[u] != u) ans = min(ans, D[u] + A[u]);
    for (auto [v, w]: adj[u]) {
      if (E[u] != E[v]) ans = min(ans, D[u] + D[v] + w);
    }
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
