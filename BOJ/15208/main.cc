#include <bits/stdc++.h>
#include <queue>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 2e18;
const int MN = 205;
int N, M, S, T;
lld D[MN][MN];
vector<pii> G[MN], Gt[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> S >> T;
  for (int i=0; i<M; i++) {
    int u, v, p; char c;
    cin >> u >> v >> c;
    if (c == '(') p = 0; if (c == ')') p = 1;
    if (c == '[') p = 2; if (c == ']') p = 3;
    if (c == '{') p = 4; if (c == '}') p = 5;
    if (c == '<') p = 6; if (c == '>') p = 7;
    G[u].push_back({v, p});
    Gt[v].push_back({u, p});
  }

  for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) D[i][j] = INF;

  using Node = array<lld, 3>;
  priority_queue<Node, vector<Node>, greater<Node>> pq;
  for (int i=1; i<=N; i++) D[i][i] = 0, pq.push({0, i, i});

  while (!pq.empty()) {
    auto [d, a, b] = pq.top(); pq.pop();
    if (d > D[a][b]) continue;

    // concat
    for (int u=1; u<=N; u++) {
      lld d1 = D[u][a] + D[a][b];
      lld d2 = D[a][b] + D[b][u];
      if (d1 < D[u][b]) D[u][b] = d1, pq.push({d1, u, b});
      if (d2 < D[a][u]) D[a][u] = d2, pq.push({d2, a, u});
    }

    // wrap
    for (auto [u, p]: Gt[a]) {
      for (auto [v, q]: G[b]) {
        bool matched = (p&1) == 0 && (p^1) == q;
        if (!matched) continue;
        lld d = D[a][b] + 2;
        if (d < D[u][v]) D[u][v] = d, pq.push({d, u, v});
      }
    }
  }

  if (D[S][T] == INF) cout << -1 << endl;
  else cout << D[S][T] << endl;

  ////////////////////////////////
  return 0;
}
