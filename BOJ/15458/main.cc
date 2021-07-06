#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;
const int MN = 1e5+5;
lld N, K, D[MN][4], color[MN];
vector<int> adj[MN];

void dfs(int u, int p) {
  if (color[u] == -1) D[u][1] = D[u][2] = D[u][3] = 1;
  else D[u][color[u]] = 1;

  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    for (int c: {1, 2, 3}) {
      D[u][c] = D[u][c] * (D[v][1] + D[v][2] + D[v][3] - D[v][c]) % MOD;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N-1; i++) {
    int x, y; cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  fill(color, color+N+1, -1);
  for (int i=0; i<K; i++) {
    int b, c; cin >> b >> c;
    color[b] = c;
  }

  dfs(1, 0);

  lld ans = 0;
  for (int c: {1, 2, 3}) ans = ans + D[1][c];
  ans %= MOD;
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
