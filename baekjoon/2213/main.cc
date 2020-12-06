#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 10'001;
int n, w[MAXN], D[MAXN][2];
vector<int> adj[MAXN];
set<int> ans;

void dfs1(int u, int p) {
  D[u][0] = 0;
  D[u][1] = w[u];

  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs1(v, u);
    D[u][0] += max(D[v][0], D[v][1]);
    D[u][1] += D[v][0];
  }
}

void dfs2(int u, int p) {
  if (ans.count(p) == 0 && D[u][1] > D[u][0]) {
    ans.insert(u);
  }
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs2(v, u);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n;
  for (int i=1; i<=n; i++) cin >> w[i];
  for (int i=1; i<=n-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs1(1, 0);
  dfs2(1, 0);

  cout << max(D[1][0], D[1][1]) << endl;
  for (auto u: ans) cout << u << " ";

  ////////////////////////////////
  return 0;
}
