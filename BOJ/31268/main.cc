#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202;
const int MQ = 1e6+5;
const lld INF = 1e18;
int N, M, Q;
lld T[MN], D[MN][MN];

struct Query { int t, x, y; };
Query qry[MQ];
vector<lld> ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> Q;
  for (int i=1; i<=N; i++) cin >> T[i];

  for (int i=1; i<=N; i++) {
    fill(D[i]+1, D[i]+N+1, INF);
    D[i][i] = 0;
  }
  for (int i=0; i<M; i++) {
    int u, v, w; cin >> u >> v >> w;
    D[u][v] = D[v][u] = w;
  }

  for (int q=0; q<Q; q++) {
    int t, x, y; cin >> t >> x >> y;
    qry[q] = {t, x, y};
    if (t == 1) T[x] += y;
  }

  // floyd
  for (int k=1; k<=N; k++)
    for (int i=1; i<=N; i++)
      for (int j=1; j<=N; j++)
        D[i][j] = min(D[i][j], D[i][k] + T[k] + D[k][j]);

  // query
  int target = 0;
  for (int q=Q-1; q>=0; q--) {
    auto [t, x, y] = qry[q];

    if (t == 1) {
      if (target == x) { T[x] -= y; continue; }

      if (target != 0) // update dist
        for (int i=1; i<=N; i++)
          for (int j=1; j<=N; j++)
            D[i][j] = min(D[i][j], D[i][target] + T[target] + D[target][j]);

      target = x;
      T[x] -= y;
    } else {
      lld d = D[x][y];
      if (target != 0) d = min(d, D[x][target] + T[target] + D[target][y]);
      ans.push_back(d);
    }
  }

  // print
  reverse(all(ans));
  for (auto x: ans) cout << (x != INF ? x : -1) << endl;

  ////////////////////////////////
  return 0;
}
