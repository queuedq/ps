#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, M, par[MAXN][20], dep[MAXN];
vector<int> adj[MAXN];

void dfs(int u, int p, int d) {
  par[u][0] = p;
  dep[u] = d;
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u, d+1);
  }
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);

  for (int k=19; k>=0; k--) {
    if (1<<k <= dep[u] - dep[v]) u = par[u][k];
  }

  if (u == v) return u;

  for (int k=19; k>=0; k--) {
    if (par[u][k] != par[v][k]) {
      u = par[u][k];
      v = par[v][k];
    }
  }

  return par[u][0];
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

  dfs(1, 0, 0);

  for (int k=1; k<20; k++) {
    for (int i=1; i<=N; i++) {
      par[i][k] = par[par[i][k-1]][k-1];
    }
  }

  cin >> M;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    cout << lca(u, v) << endl;
  }

  ////////////////////////////////
  return 0;
}
