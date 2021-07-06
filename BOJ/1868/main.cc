#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 5e5+5;
int N, seen[MN][30], D[MN], ans;
vector<int> adj[MN];

void dfs(int u, int p) {
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    for (int i=0; i<30; i++) seen[u][i] += seen[v][i];
  }

  for (int i=0; i<30; i++) {
    if (seen[u][i] >= 2) D[u] = i+1;
    else if (seen[u][i] == 1 && D[u] == i) D[u]++;
  }

  seen[u][D[u]] = 1;
  for (int i=0; i<D[u]; i++) seen[u][i] = 0;

  ans = max(ans, D[u]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  dfs(1, 0);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
