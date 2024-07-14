#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, M;
vector<pll> adj[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  vector<int> ds;
  for (int i=0; i<M; i++) {
    int u, v, d; cin >> u >> v >> d;
    adj[u].push_back({d, v});
    adj[v].push_back({d, u});
    ds.push_back(d);
  }

  for (int u=1; u<=N; u++) sort(adj[u].rbegin(), adj[u].rend());
  sort(ds.rbegin(), ds.rend());

  lld ans = 0;
  for (int i=0; i<min(sz(ds), 2); i++) ans += ds[i]; // at most 2 edges

  for (int u=1; u<=N; u++) { // 3 edges
    for (auto [d, v]: adj[u]) {
      for (int i=0; i<min(sz(adj[u]), 3); i++) {
        auto [a, x] = adj[u][i];
        for (int j=0; j<min(sz(adj[v]), 3); j++) {
          auto [b, y] = adj[v][j];
          if (x == v || y == u || x == y) continue;
          ans = max(ans, d+a+b);
        }
      }
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
