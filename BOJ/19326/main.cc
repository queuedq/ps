#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, M, a[MN], b[MN];
int par[20][MN], dep[MN];
int S[MN], covered[MN];
vector<int> adj[MN];
vector<int> paths[MN]; // path a-b in paths[lca(a, b)];

void dfs(int u, int p, int d) {
  par[0][u] = p;
  dep[u] = d;
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u, d+1);
  }
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int k=19; k>=0; k--) {
    if (dep[u]-dep[v] >= 1<<k) u = par[k][u];
  }
  if (u == v) return u;
  for (int k=19; k>=0; k--) {
    if (par[k][u] != par[k][v]) u = par[k][u], v = par[k][v];
  }
  return par[0][u];
}

void cover(int u, int p) {
  covered[u] = 1;
  for (auto v: adj[u]) {
    if (v == p) continue;
    if (!covered[v]) cover(v, u);
  }
}

void select(int u, int p) {
  for (auto v: adj[u]) {
    if (v == p) continue;
    select(v, u);
  }

  // if there is an uncovered path, choose u (=lca)
  for (auto i: paths[u]) {
    if (!covered[a[i]] && !covered[b[i]]) { S[u] = 1; break; }
  }

  // cover paths crossing u
  if (S[u]) cover(u, p);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0, 0);
  for (int k=1; k<20; k++)
    for (int u=1; u<=N; u++)
      par[k][u] = par[k-1][par[k-1][u]];

  cin >> M;
  for (int i=1; i<=M; i++) {
    cin >> a[i] >> b[i];
    paths[lca(a[i], b[i])].push_back(i);
  }

  select(1, 0);

  int cnt = 0;
  for (int u=1; u<=N; u++) cnt += S[u];
  cout << cnt << endl;
  for (int u=1; u<=N; u++) if (S[u]) cout << u << " ";

  ////////////////////////////////
  return 0;
}
