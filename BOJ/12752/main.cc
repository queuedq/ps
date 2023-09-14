#include <bits/stdc++.h>
#include <queue>
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
lld N, K, M, S[5], dst[1<<5][MN];
vector<pll> adj[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K >> M;
  for (int i=0; i<K; i++) cin >> S[i];
  for (int i=1; i<=M; i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  for (int i=0; i<K; i++) {
    auto D = dst[1<<i];
    fill(D, D+N+1, INF);

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({D[S[i]] = 0, S[i]});

    while (!pq.empty()) {
      auto [d, u] = pq.top(); pq.pop();
      if (D[u] < d) continue;
      for (auto [v, w]: adj[u]) {
        if (d+w >= D[v]) continue;
        D[v] = d+w;
        pq.push({d+w, v});
      }
    }
  }

  for (int m=1; m<1<<K; m++) {
    if (__builtin_popcount(m) == 1) continue;

    auto D = dst[m];
    fill(D, D+N+1, INF);
    for (int a=m-1; a>0; a=(a-1)&m) {
      int b = m^a;
      for (int u=1; u<=N; u++) D[u] = min(D[u], dst[a][u] + dst[b][u]);
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (int u=1; u<=N; u++) pq.push({D[u], u});
  
    while (!pq.empty()) {
      auto [d, u] = pq.top(); pq.pop();
      if (D[u] < d) continue;
      for (auto [v, w]: adj[u]) {
        if (d+w >= D[v]) continue;
        D[v] = d+w;
        pq.push({d+w, v});
      }
    }
  }

  lld ans = INF;
  for (int u=1; u<=N; u++) ans = min(ans, dst[(1<<K)-1][u]);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
