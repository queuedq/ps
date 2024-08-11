#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;
const int MN = 101010;
int N, M, vst[MN], color[MN];
vector<pii> adj[MN];

bool dfs(int u, int c) {
  if (vst[u]) return color[u] == c;
  vst[u] = 1;
  color[u] = c;

  bool ok = 1;
  for (auto [v, w]: adj[u]) ok &= dfs(v, c^w);
  return ok;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int u, v, c; cin >> u >> v >> c;
    adj[u].push_back({v, !c});
    adj[v].push_back({u, !c});
  }

  int comp = 0;
  bool ok = 1;
  for (int u=1; u<=N; u++) {
    if (vst[u]) continue;
    ok &= dfs(u, 0);
    comp++;
  }

  if (ok) {
    lld ans = 1;
    for (int i=0; i<comp-1; i++) ans = ans*2 % MOD;
    cout << ans << endl;
  } else {
    cout << 0 << endl;
  }

  ////////////////////////////////
  return 0;
}
