#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 10'005;
int N, M;
vector<int> adj[MAXN];

int id, dfn[MAXN], low[MAXN], cut[MAXN];

void dfs(int u, int p) {
  dfn[u] = low[u] = ++id;
  int children = 0;
  for (auto v: adj[u]) {
    if (v == p) continue;
    if (dfn[v]) {
      low[u] = min(low[u], dfn[v]);
      continue;
    }
    dfs(v, u);
    low[u] = min(low[u], low[v]);
    if (p && low[v] >= dfn[u]) cut[u] = true;
    children++;
  }
  if (!p && children > 1) cut[u] = true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i=1; i<=N; i++) {
    if (!dfn[i]) dfs(i, 0);
  }

  int ans = 0;
  for (int i=1; i<=N; i++) {
    if (cut[i]) ans++;
  }

  cout << ans << endl;
  for (int i=1; i<=N; i++) {
    if (cut[i]) cout << i << " ";
  }
  cout << endl;

  ////////////////////////////////
  return 0;
}
