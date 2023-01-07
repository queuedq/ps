#include <bits/stdc++.h>
#include <climits>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
lld N, K, ans = LLONG_MAX;
vector<pll> adj[MN];
map<lld, lld> S[MN]; // S[len] = min dep

void set_min(map<lld, lld> &mp, lld k, lld v) {
  if (!mp.count(k)) mp[k] = LLONG_MAX;
  mp[k] = min(mp[k], v);
}

void dfs(int u, int p, lld dep, lld len) {
  set_min(S[u], len, dep);

  for (auto [v, w]: adj[u]) {
    if (v == p) continue;
    dfs(v, u, dep+1, len+w);

    // compare
    if (sz(S[u]) < sz(S[v])) swap(S[u], S[v]);
    for (auto [l, d]: S[v]) {
      lld l2 = K - l + 2*len; // l1 + l2 - 2*len = K
      if (S[u].count(l2)) ans = min(ans, S[u][l2] + d - 2*dep);
    }

    // merge
    for (auto [l, d]: S[v]) set_min(S[u], l, d);
    S[v].clear();
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N-1; i++) {
    lld u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  dfs(0, -1, 0, 0);
  if (ans == LLONG_MAX) cout << -1 << endl;
  else cout << ans << endl;

  ////////////////////////////////
  return 0;
}
