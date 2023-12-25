#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9;
const int MN = 101010;
// dst: max dist to uncovered node
// cov: remaining coverage length
int N, K, dst[MN], cov[MN], cnt;
vector<int> adj[MN];

void dfs(int u, int p) {
  dst[u] = 0;
  cov[u] = -INF;

  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    dst[u] = max(dst[u], dst[v]+1);
    cov[u] = max(cov[u], cov[v]-1);
  }

  // cover nodes
  if (dst[u] <= cov[u]) dst[u] = -INF;

  // place warehouse
  if (dst[u] == K || (dst[u] >= 0 && p == 0))
    dst[u] = -INF, cov[u] = K, cnt++;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0);
  cout << cnt << endl;

  ////////////////////////////////
  return 0;
}
