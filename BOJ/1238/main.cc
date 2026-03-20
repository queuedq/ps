#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9;
const int MN = 1010;
int N, M, X, D1[MN], D2[MN];
vector<pii> adj[MN], rev[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> X;
  for (int i=0; i<M; i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    rev[v].push_back({u, w});
  }

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  fill(D1, D1+N+1, INF);
  pq.push({D1[X] = 0, X});

  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (D1[u] < d) continue;
    for (auto [v, w]: adj[u]) {
      if (d+w < D1[v]) pq.push({D1[v] = d+w, v});
    }
  }

  fill(D2, D2+N+1, INF);
  pq.push({D2[X] = 0, X});

  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (D2[u] < d) continue;
    for (auto [v, w]: rev[u]) {
      if (d+w < D2[v]) pq.push({D2[v] = d+w, v});
    }
  }

  int ans = 0;
  for (int u=1; u<=N; u++) {
    ans = max(ans, D1[u]+D2[u]);
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
