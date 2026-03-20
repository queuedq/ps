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
int N, a, b, c, deg[MN], dst[3][MN];
vector<int> adj[MN];

void dfs(int u, int p, int d, int k) {
  dst[k][u] = d;
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u, d+1, k);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  cin >> a >> b >> c;
  
  dfs(a, 0, 0, 0);
  dfs(b, 0, 0, 1);
  dfs(c, 0, 0, 2);

  bool ok = 0;
  for (int u=1; u<=N; u++) {
    if (deg[u] != 1) continue;
    if (dst[0][u] < dst[1][u] && dst[0][u] < dst[2][u]) ok = 1;
  }
  cout << (ok ? "YES" : "NO") << endl;

  ////////////////////////////////
  return 0;
}
