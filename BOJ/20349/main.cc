#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 10101;
lld N, M, Q, vst[MN], par[MN], val[MN], r;
vector<pll> adj[MN];
vector<lld> cyc; // cycle basis weights

void dfs(int u, int p, lld x) {
  if (vst[u]) return;
  vst[u] = 1;
  par[u] = p;
  val[u] = val[p] ^ x;
  for (auto [v, w]: adj[u]) dfs(v, u, w);
}

void gaussian() {
  r = 0; // rank
  for (int b=63; b>=0 && r<sz(cyc); b--) {
    // find pivot
    for (int i=r; i<sz(cyc); i++) {
      if (cyc[i]>>b & 1) swap(cyc[r], cyc[i]);
    }
    if (!(cyc[r]>>b & 1)) continue;

    // eliminate
    for (int i=r+1; i<sz(cyc); i++) {
      if (cyc[i]>>b & 1) cyc[i] ^= cyc[r];
    }
    r++;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> Q;
  for (int i=0; i<M; i++) {
    lld u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  dfs(1, 0, 0);

  for (int u=1; u<=N; u++) {
    for (auto [v, w]: adj[u]) {
      if (par[u] == v || par[v] == u) continue;
      cyc.push_back(val[u] ^ val[v] ^ w);
    }
  }

  gaussian();

  for (int i=0; i<Q; i++) {
    int u, v; cin >> u >> v;
    lld path = val[u] ^ val[v];
    for (int j=0; j<r; j++) {
      if ((path ^ cyc[j]) < path) path ^= cyc[j];
    }
    cout << path << endl;
  }

  ////////////////////////////////
  return 0;
}
