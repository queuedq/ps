#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
const lld MOD = 1e9+7;
lld N, D[MN], E[MN], ans;
vector<pll> adj[MN];

void dfs(int u, int p) {
  for (auto [v, w]: adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    lld x = (D[v]*w + w) % MOD;
    D[u] = (D[u] + x) % MOD;
    E[u] = (E[u] + x*x%MOD) % MOD;
  }
  lld x = (D[u]*D[u] - E[u]) % MOD;
  x = (x * (MOD+1)/2) % MOD;
  ans = (ans + D[u] + x) % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  dfs(1, 0);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
