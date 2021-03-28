#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 4005;
int N, M, G[MAXN];
lld D[MAXN][MAXN];
bool vst[MAXN][MAXN];
vector<pii> adj[MAXN];

struct Pos {
  int u, gas; lld cost;

  bool operator <(const Pos p) const { return cost > p.cost; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) cin >> G[i];
  for (int i=1; i<=M; i++) {
    int u, v, len; cin >> u >> v >> len;
    adj[u].push_back({v, len});
    adj[v].push_back({u, len});
  }

  for (int i=1; i<=N; i++) {
    fill(D[i], D[i]+MAXN, -1);
  }

  lld ans = 0;

  priority_queue<Pos> pq;
  pq.push({1, G[1], 0});
  while (!pq.empty()) {
    auto [u, g, c] = pq.top(); pq.pop();
    if (vst[u][g]) continue;
    vst[u][g] = true;

    if (u == N) { ans = c; break; }

    for (auto [v, len]: adj[u]) {
      int gas = min(g, G[v]);
      lld cost = c + g * len;
      if (D[v][gas] == -1 || cost < D[v][gas]) {
        D[v][gas] = cost;
        pq.push({v, gas, cost});
      }
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
