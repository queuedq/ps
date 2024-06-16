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
int N, M, K, r[MN], vst[MN];
vector<pii> adj[MN];
vector<int> ans;

bool dfs(int u) { // reversed path
  ans.push_back(u);
  if (vst[u]) return 1; // may visit in the first step
  vst[u] = 1;
  
  // step 1: color u
  int x = 0;
  for (auto [v, c]: adj[u]) {
    if (c == r[u]) { x = v; break; }
  }
  if (!x) return 0;
  bool ok = dfs(x); ans.push_back(u);

  // step 2: dfs
  for (auto [v, c]: adj[u]) {
    if (!vst[v]) { ok &= dfs(v); ans.push_back(u); }
  }
  return ok;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int u=1; u<=N; u++) cin >> r[u];
  for (int i=0; i<M; i++) {
    int u, v, c; cin >> u >> v >> c;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }

  bool ok = dfs(1);
  for (int u=1; u<=N; u++) ok &= vst[u];
  reverse(all(ans));

  if (ok) {
    cout << "YES" << endl;
    cout << sz(ans) << endl;
    for (auto u: ans) cout << u << " ";
    cout << endl;
  } else {
    cout << "NO" << endl;
  }

  ////////////////////////////////
  return 0;
}
