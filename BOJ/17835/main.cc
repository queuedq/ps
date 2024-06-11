#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, M, K;
vector<pii> adj[MN];
lld dst[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=0; i<M; i++) {
    int u, v, c; cin >> u >> v >> c;
    adj[v].push_back({u, c}); // reversed graph
  }

  fill_n(dst+1, N, LLONG_MAX);
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  for (int i=0; i<K; i++) {
    int u; cin >> u;
    dst[u] = 0;
    pq.push({0, u});
  }

  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d > dst[u]) continue;

    for (auto [v, c]: adj[u]) {
      if (dst[u]+c < dst[v]) {
        dst[v] = dst[u]+c;
        pq.push({dst[v], v});
      }
    }
  }

  lld i = max_element(dst+1, dst+N+1) - dst;
  cout << i << endl;
  cout << dst[i] << endl;

  ////////////////////////////////
  return 0;
}
