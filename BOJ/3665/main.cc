#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, M, rnk[505], adj[505][505], deg[505], ans[505];

void solve() {
  cin >> N;

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) adj[i][j] = 0;
    deg[i] = ans[i] = 0;
  }

  for (int i=1; i<=N; i++) {
    cin >> rnk[i];
    for (int j=1; j<i; j++) adj[rnk[i]][rnk[j]] = 1;
  }

  cin >> M;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    swap(adj[u][v], adj[v][u]);
  }

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) deg[i] += adj[i][j];
    ans[deg[i]] = i;
  }

  if (count(ans, ans+N, 0) > 0) { cout << "IMPOSSIBLE" << endl; return; }
  for (int i=0; i<N; i++) cout << ans[i] << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) solve();

  ////////////////////////////////
  return 0;
}
