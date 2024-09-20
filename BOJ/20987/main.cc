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
int N, M;
unordered_map<int, vector<pll>> adj[MN];
unordered_map<int, lld> S[MN], dst[MN];

struct Node {
  lld u, c, d; // c: color for last type 3 move (see below)
  bool operator<(const Node &X) const { return d > X.d; }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int u, v, c, p; cin >> u >> v >> c >> p;
    adj[u][c].push_back({v, p});
    adj[v][c].push_back({u, p});
    S[u][c] += p;
    S[v][c] += p;
  }

  // 3 types of moves
  // 1. change u -> v color
  // 2. change c-colored edges except u -> v
  // 3. free move u -> v, next move must be type 2 for color c
  priority_queue<Node> pq;
  pq.push({1, 0, dst[1][0] = 0});

  while (!pq.empty()) {
    auto [u, c, d] = pq.top(); pq.pop();
    if (d != dst[u][c]) continue;

    if (c == 0) {
      for (auto [c, edges]: adj[u]) {
        for (auto [v, p]: edges) {
          // type 1, 2
          lld w = min(p, S[u][c] - p);
          if (!dst[v].count(0) || dst[v][0] > d + w)
            pq.push({v, 0, dst[v][0] = d + w});

          // type 3
          if (!dst[v].count(c) || dst[v][c] > d)
            pq.push({v, c, dst[v][c] = d});
        }
      }

    } else {
      for (auto [v, p]: adj[u][c]) {
        // type 2
        lld w = S[u][c] - p;
        if (!dst[v].count(0) || dst[v][0] > d + w)
          pq.push({v, 0, dst[v][0] = d + w});
      }
    }
  }

  if (!dst[N].count(0)) cout << -1 << endl;
  else cout << dst[N][0] << endl;

  ////////////////////////////////
  return 0;
}
