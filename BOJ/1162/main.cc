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
const int MK = 21;
int N, M, K;
lld dst[MN][MK];
vector<pll> adj[MN];

struct Node {
  lld u, k, d;
  bool operator<(const Node &n) const { return d > n.d; }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=0; i<M; i++) {
    lld u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  fill_n(&dst[0][0], MN*MK, LLONG_MAX);
  priority_queue<Node> pq;
  pq.push({1, 0, 0});
  dst[1][0] = 0;

  while (!pq.empty()) {
    auto [u, k, d] = pq.top(); pq.pop();
    if (d > dst[u][k]) continue;
    if (u == N) { cout << dst[u][k] << endl; return 0; }

    for (auto [v, w]: adj[u]) {
      if (d+w < dst[v][k]) {
        dst[v][k] = d+w;
        pq.push({v, k, d+w});
      }
      if (k+1 <= K && d < dst[v][k+1]) {
        dst[v][k+1] = d;
        pq.push({v, k+1, d});
      }
    }
  }

  ////////////////////////////////
  return 0;
}
