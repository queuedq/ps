#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1'000'005;
int N, M, dfn[MN], low[MN], par[MN], idx;
int root[MN], vst[MN];
vector<int> adj[MN], T[MN];

void bcc(int u, int p) {
  dfn[u] = low[u] = ++idx;
  par[u] = p;
  for (auto v: adj[u]) {
    if (v == p) continue;
    if (dfn[v]) { low[u] = min(low[u], dfn[v]); continue; }
    bcc(v, u);
    low[u] = min(low[u], low[v]);
  }
}

int find(int x) {
  if (root[x] == x) return x;
  return root[x] = find(root[x]);
}

void merge(int x, int y) {
  x = find(x), y = find(y);
  root[y] = x;
}

pii dfs(int u, int p, int d) {
  vst[u] = 1;
  pii res = {d, u};
  for (auto v: T[u]) {
    if (v == p) continue;
    res = max(res, dfs(v, u, d+1));
  }
  return res;
}

int diameter(int u) {
  auto [_, v] = dfs(u, -1, 0);
  auto [d, w] = dfs(v, -1, 0);
  return d;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int u=0; u<N; u++) if (!dfn[u]) bcc(u, -1);
  
  iota(root, root+N, 0);
  for (int u=0; u<N; u++) {
    if (dfn[u] > low[u]) merge(par[u], u); // bcc
  }

  for (int u=0; u<N; u++) {
    if (par[u] == -1) continue;
    if (dfn[u] <= low[u]) { // bridge
      int a = find(u), b = find(par[u]);
      T[a].push_back(b);
      T[b].push_back(a);
    }
  }

  int ans = 0;
  for (int u=0; u<N; u++) {
    int a = find(u);
    if (!vst[a]) ans += diameter(a) + 1;
  }
  cout << ans-1 << endl;

  ////////////////////////////////
  return 0;
}
