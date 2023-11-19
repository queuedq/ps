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
vector<int> adj[MN];
int N, Q, par[MN][20], dep[MN];

void dfs(int u, int p, int d) {
  par[u][0] = p;
  dep[u] = d;
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u, d+1);
  }
}

int lca(int u, int v) {
  // make same depth
  if (dep[u] < dep[v]) swap(u, v);
  for (int k=19; k>=0; k--) {
    if (dep[par[u][k]] >= dep[v]) u = par[u][k];
  }

  // binary lifting
  if (u == v) return u;
  for (int k=19; k>=0; k--) {
    if (par[u][k] != par[v][k]) {
      u = par[u][k];
      v = par[v][k];
    }
  }
  return par[u][0];
}

int dist(int u, int v) {
  int l = lca(u, v);
  return dep[u] + dep[v] - dep[l]*2;
}

int ancestor(int u, int d) {
  for (int k=19; k>=0; k--) {
    if (d>>k & 1) u = par[u][k];
  }
  return u;
}

int midpoint(int u, int v) {
  int l = lca(u, v);
  int d = dep[u] + dep[v] - dep[l]*2;
  if (d/2 <= dep[u]-dep[l]) return ancestor(u, d/2);
  else return ancestor(v, d/2);
}

bool check(int a, int b, int c, int x) {
  int r1 = dist(a, x);
  int r2 = dist(b, x);
  int r3 = dist(c, x);
  return r1 == r2 && r2 == r3;
}

int circumcenter(int a, int b, int c) {
  int m1 = midpoint(a, b);
  int m2 = midpoint(b, c);
  int m3 = midpoint(c, a);

  if (m1 == m2) return check(a, b, c, m1) ? m1 : -1;
  else if (m2 == m3) return check(a, b, c, m2) ? m2 : -1;
  else if (m3 == m1) return check(a, b, c, m3) ? m3 : -1;
  return -1;
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
  }

  // lca preprocessing
  dfs(1, 0, 1);

  for (int k=1; k<20; k++) {
    for (int i=1; i<=N; i++) {
      par[i][k] = par[par[i][k-1]][k-1];
    }
  }

  // queries
  cin >> Q;
  for (int q=0; q<Q; q++) {
    int a, b, c; cin >> a >> b >> c;
    cout << circumcenter(a, b, c) << endl;
  }

  ////////////////////////////////
  return 0;
}
