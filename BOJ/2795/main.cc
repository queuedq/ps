#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using piii = pair<int, pii>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 105;
const int INF = 1e9;
int N, M, adj[MN][MN], dst[MN][MN], D[MN][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    adj[u][v] = 1;
  }

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      if (i != j) dst[i][j] = adj[i][j] ? 1 : INF;
      D[i][j] = INF;
    }
  }

  for (int k=1; k<=N; k++)
    for (int i=1; i<=N; i++)
      for (int j=1; j<=N; j++)
        dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);

  priority_queue<piii, vector<piii>, greater<piii>> pq;
  D[1][1] = 1;
  pq.push({0, {1, 1}});

  while (!pq.empty()) {
    auto [d, p] = pq.top(); pq.pop();
    auto [u, v] = p;
    if (d > D[u][v]) continue;

    auto insert = [&](int u1, int v1, int d1) {
      if (d1 >= D[u1][v1]) return;
      D[u1][v1] = d1;
      pq.push({d1, {u1, v1}});
    };

    if (u != v && dst[u][v] < INF)
      insert(v, u, D[u][v] + dst[u][v] - 1);

    for (int x=1; x<=N; x++) {
      if (x != v && adj[u][x])
        insert(x, v, D[u][v] + 1);

      if (x != u && adj[x][v])
        insert(u, x, D[u][v] + 1);

      if (adj[u][x] && adj[x][v])
        insert(x, x, D[u][v] + 1);
    }
  }

  cout << D[2][2] << endl;

  ////////////////////////////////
  return 0;
}
