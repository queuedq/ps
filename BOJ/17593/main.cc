#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MAXN = 505;
const lld INF = 1e18;
lld N, M, T, D;
bool repair[MAXN];
vector<pll> adj[MAXN];
lld w[MAXN][MAXN], dist[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> T >> D;
  for (int i=0; i<T; i++) {
    lld a; cin >> a;
    repair[a] = true;
  }
  repair[1] = repair[N] = true;

  for (int i=1; i<=N; i++) {
    dist[i] = INF;
    for (int j=1; j<=N; j++) {
      w[i][j] = i==j ? 0 : INF;
    }
  }

  for (int i=0; i<M; i++) {
    lld a, b, c; cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
    w[a][b] = w[b][a] = c;
  }

  for (int k=1; k<=N; k++) {
    for (int i=1; i<=N; i++) {
      for (int j=1; j<=N; j++) {
        w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
      }
    }
  }

  priority_queue<pll, vector<pll>, greater<pll>> pq;
  pq.push({0, 1});
  dist[1] = 0;
  lld ans = -1;
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (u == N) { ans = d; break; }
    if (d > dist[u]) continue;

    for (int v=1; v<=N; v++) {
      if (u == v || !repair[v] || w[u][v] > D) continue;
      if (d + w[u][v] < dist[v]) {
        dist[v] = d + w[u][v];
        pq.push({d + w[u][v], v});
      }
    }
  }

  if (ans == -1) cout << "stuck" << endl;
  else cout << ans << endl;

  ////////////////////////////////
  return 0;
}
