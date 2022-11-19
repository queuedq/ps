#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 222'225;
int N, Q, par[MN][20], dep[MN], sum[MN];
vector<int> adj[MN];

struct Ans {
  int a, b, c;
  bool operator <(Ans X) const {
    if (c == X.c) return pii(a, b) > pii(X.a, X.b);
    return c < X.c;
  }
};
Ans ans;

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

int dfs2(int u, int p) {
  for (auto v: adj[u]) {
    if (v == p) continue;
    sum[u] += dfs2(v, u);
  }
  if (p != 0) ans = max(ans, {min(u, p), max(u, p), sum[u]});
  return sum[u];
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> Q;
  for (int i=1; i<=N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0, 1);

  for (int k=1; k<20; k++) {
    for (int i=1; i<=N; i++) {
      par[i][k] = par[par[i][k-1]][k-1];
    }
  }

  for (int i=1; i<=Q; i++) {
    int u, v; cin >> u >> v;
    int p = lca(u, v);
    sum[u]++;
    sum[v]++;
    sum[p] -= 2;
  }

  ans = {-1, 0, 0};
  dfs2(1, 0);
  auto [a, b, c] = ans;
  cout << a << " " << b << " " << c << endl;

  ////////////////////////////////
  return 0;
}
