#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MAXN = 505;
lld N, M, T, D;
bool refill[MAXN];
vector<pll> adj[MAXN]; // {u, w}
lld tr[MAXN]; // tire

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> T >> D;
  for (int i=0; i<T; i++) {
    lld a; cin >> a;
    refill[a] = true;
  }

  for (int i=0; i<M; i++) {
    lld a, b, w; cin >> a >> b >> w;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }

  priority_queue<pair<lld, pll>, vector<pair<lld, pll>>, greater<pair<lld, pll>>> pq; // {dist, {u, tire}}
  pq.push({0, {1, D}});
  lld ans = -1;
  while (!pq.empty()) {
    auto [dist, _] = pq.top(); pq.pop();
    auto [u, tire] = _;

    if (u == N) { ans = dist; break; }
    if (refill[u]) tire = D;
    if (tire <= tr[u]) continue;
    tr[u] = tire;

    for (auto [v, w]: adj[u]) {
      if (tire-w < 0) continue;
      pq.push({dist+w, {v, tire-w}});
    }
  }

  if (ans == -1) cout << "stuck" << endl;
  else cout << ans << endl;

  ////////////////////////////////
  return 0;
}
