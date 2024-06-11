#include <bits/stdc++.h>
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
int N, M, S, T, deg[MN];
lld D[MN][2];
vector<pii> adj[MN];

struct Node {
  int u, t; lld d; // t=0: shortest, t=1: longest
  bool operator<(const Node &X) const { return d > X.d; }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> S >> T;
  for (int i=0; i<M; i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[v].push_back({u, w});
    deg[u]++;
  }

  for (int i=0; i<N; i++) D[i][0] = INF;
  priority_queue<Node> pq;
  pq.push({T, 0, 0}); pq.push({T, 1, 0});
  D[T][0] = D[T][1] = 0;

  while (!pq.empty()) {
    auto [u, t, d] = pq.top(); pq.pop();
    if (D[u][t] != d) continue;

    if (t == 0) {
      for (auto [v, w]: adj[u]) {
        D[v][1] = max(D[v][1], d+w);
        if (--deg[v] == 0) pq.push({v, !t, D[v][1]});
      }
    } else {
      for (auto [v, w]: adj[u]) {
        if (d+w < D[v][0]) {
          D[v][0] = d+w; // shortest
          pq.push({v, !t, D[v][0]});
        }
      }
    }
  }

  if (deg[S]) cout << "infinity" << endl;
  else cout << D[S][1] << endl;

  ////////////////////////////////
  return 0;
}
