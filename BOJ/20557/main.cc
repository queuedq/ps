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
int N, M, Q, vst[MN], D[MN], E[MN], psum[MN];
vector<pii> adj[MN];
vector<int> cyc;

void dfs(int u, int p, int d) {
  if (vst[u]) return;
  vst[u] = 1;
  D[u] = d;
  for (auto [v, w]: adj[u]) {
    if (v == p) continue;
    if (vst[v]) cyc.push_back(D[u]^D[v]^w);
    else dfs(v, u, d^w);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> Q;
  for (int i=0; i<M; i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  dfs(1, 0, 0);

  // gaussian elimination
  int r = 0;
  for (int k=29; k>=0; k--) {
    // find pivot
    int p = -1;
    for (int i=r; i<sz(cyc); i++) {
      if (cyc[i]>>k & 1) { p = i; break; }
    }

    // row ops
    if (p == -1) continue;
    swap(cyc[r], cyc[p]);
    for (int i=r+1; i<sz(cyc); i++) {
      if (cyc[i]>>k & 1) cyc[i] ^= cyc[r];
    }
    r++;
  }
  cyc.resize(r);

  // get E[u] = max(D[u] ^ cycles)
  // d(u, v) = E[u] ^ E[v] ^ E[1]
  for (int u=1; u<=N; u++) {
    E[u] = D[u];
    for (auto c: cyc) {
      if ((E[u] ^ c) > E[u]) E[u] ^= c;
    }
  }
  for (int u=1; u<=N; u++) psum[u] = psum[u-1] ^ E[u];

  // query
  for (int q=0; q<Q; q++) {
    int l, r; cin >> l >> r;

    int ans = 0;
    lld cnt = (lld)(r-l+1)*(r-l)/2;
    if (cnt & 1) ans ^= E[1];
    if ((r-l) & 1) ans ^= psum[r] ^ psum[l-1];
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
