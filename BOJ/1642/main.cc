#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
lld N, M, K, fact[MN];
vector<int> adj[MN];
int deg[MN], deg2[MN], vst[MN];
int iso_edge, iso_vtx, caterpillar; // components

int dfs(int u, int p) {
  if (vst[u] || deg2[u] > 2) return -1; // cycle or branch
  vst[u] = 1;

  int len = 1;
  for (auto v: adj[u]) {
    if (v == p || deg[v] == 1) continue;
    int sub = dfs(v, u);
    if (sub < 0) return -1;
    len += sub;
  }
  return len;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  fact[0] = 1;
  for (int i=1; i<=N; i++) fact[i] = fact[i-1] * i % K;

  for (int u=1; u<=N; u++) deg[u] = sz(adj[u]);
  for (int u=1; u<=N; u++) {
    for (auto v: adj[u]) deg2[u] += deg[v] >= 2;
  }

  // caterpillars
  bool ok = 1;
  vector<int> P; // path lengths
  for (int u=1; u<=N; u++) {
    if (deg[u] < 2 || vst[u]) continue;
    int len = dfs(u, 0);
    if (len < 0) { ok = 0; break; }
    P.push_back(len);
  }

  if (!ok) return cout << 0 << endl, 0;

  // isolated components
  for (int u=1; u<=N; u++) {
    if (deg[u] == 0) {
      iso_vtx++;
    } else if (deg[u] == 1) {
      int v = adj[u][0];
      iso_edge += deg[v] == 1;
    }
  }
  iso_edge /= 2;

  // count orientation
  lld ans = 1;

  for (auto len: P) { // path orientation
    if (len == 1) ans = ans * 2 % K;
    else ans = ans * 4 % K;
  }
  for (int u=1; u<=N; u++) { // caterpillar leg permutation
    if (deg[u] >= 2) ans = ans * fact[deg[u] - deg2[u]] % K;
  }

  for (int i=0; i<iso_edge; i++) ans = ans * 2 % K; // isolated edge orientation

  // count permutation
  ans = ans * fact[P.size() + iso_edge] % K; // component permutation

  for (int i=0; i<iso_vtx; i++) { // insert isolated vertices
    ans = ans * (N-i+1) % K;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
