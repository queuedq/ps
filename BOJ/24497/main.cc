#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505050;
lld N, M, a[MN], b[MN], ans[MN], vst[MN];
vector<pll> adj[MN];

void dfs1(int u, int r) {
  for (auto [v, k]: adj[u]) {
    if (vst[v] == 1) {
      // (a[u]+a[v])*x + (b[u]+b[v]) = k
      if (a[u] == a[v]) ans[r] = (k-b[u]-b[v]) / (a[u]+a[v]);
      continue;
    }
    vst[v] = 1;
    a[v] = -a[u];
    b[v] = k-b[u];
    dfs1(v, r);
  }
}

void dfs2(int u, lld x) {
  if (vst[u] == 2) return;
  vst[u] = 2;
  ans[u] = a[u]*x + b[u];
  for (auto [v, k]: adj[u]) dfs2(v, x);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    lld u, v, k; cin >> u >> v >> k;
    adj[u].push_back({v, k});
    adj[v].push_back({u, k});
  }

  fill(ans+1, ans+N+1, LLONG_MAX);
  for (int u=1; u<=N; u++) {
    if (vst[u]) continue;

    vst[u] = 1, a[u] = 1, b[u] = 0;
    dfs1(u, u);
    if (ans[u] == LLONG_MAX) { cout << "ERROR" << endl; return 0; }

    dfs2(u, ans[u]);
  }

  for (int u=1; u<=N; u++) cout << ans[u] << " ";

  ////////////////////////////////
  return 0;
}
