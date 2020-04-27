#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 4005;
int N, M, A[MAXN];
vector<pii> adj[MAXN];
bool vst[MAXN][2501];

struct Pos {
  int u, gas; lld cost;
  bool operator <(Pos P) const { return cost > P.cost; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int i=1; i<=M; i++) {
    int a, b, w; cin >> a >> b >> w;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }

  priority_queue<Pos> pq;
  pq.push({1, A[1], 0});
  while (!pq.empty()) {
    auto [u, gas, cost] = pq.top(); pq.pop();
    if (vst[u][gas]) continue;
    vst[u][gas] = true;
    if (u == N) {
      cout << cost << endl;
      return 0;
    }
    gas = min(gas, A[u]);
    for (auto [v, w]: adj[u]) {
      if (!vst[v][gas]) pq.push({v, gas, cost + gas*w});
    }
  }

  ////////////////////////////////
  return 0;
}
