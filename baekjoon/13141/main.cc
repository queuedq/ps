#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 205;
int N, M;
vector<pii> adj[MAXN];
int dist[MAXN];

double calc(int start) {
  for (int i=1; i<=N; i++) dist[i] = -1;

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, start});
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (dist[u] != -1) continue;
    dist[u] = d;
    for (auto [v, w]: adj[u]) {
      if (dist[v] == -1) pq.push({d+w, v});
    }
  }

  double res = 0;
  for (int u=1; u<=N; u++) {
    for (auto [v, w]: adj[u]) {
      // assert(abs(dist[u]-dist[v]) <= w);
      res = max(res, (dist[u]+dist[v]+w)/2.0);
    }
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int a, b, w; cin >> a >> b >> w;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }

  double ans = 1e9;
  for (int i=1; i<=N; i++) {
    ans = min(ans, calc(i));
  }
  cout << fixed << setprecision(1) << ans << endl;

  ////////////////////////////////
  return 0;
}
