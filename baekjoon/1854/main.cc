#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
int N, M, K;
vector<pll> adj[MAXN];
vector<lld> D[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=0; i<M; i++) {
    lld a, b, c; cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }

  priority_queue<pll, vector<pll>, greater<pll>> pq;
  pq.push({0, 1});
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (D[u].size() == K) continue;
    D[u].push_back(d);
    for (auto [v, w]: adj[u]) {
      if (D[v].size() == K) continue;
      pq.push({d+w, v});
    }
  }

  for (int i=1; i<=N; i++) {
    if (D[i].size() < K) cout << -1 << endl;
    else cout << D[i][K-1] << endl;
  }

  ////////////////////////////////
  return 0;
}
