#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, M, last, dfn[MN], vst[MN], D[MN]; // D: remaining child
vector<int> adj[MN];
vector<pair<int, pii>> ans;

void dfs(int u) {
  if (dfn[u]) return;
  dfn[u] = ++last;
  for (auto v: adj[u]) dfs(v);
}

void dp(int u) {
  if (vst[u]) return;
  vst[u] = 1;

  for (auto v: adj[u]) {
    if (dfn[v] < dfn[u]) continue;
    dp(v);
  }

  for (auto v: adj[u]) {
    if (dfn[v] < dfn[u]) continue;
    if (D[v]) { ans.push_back({v, {D[v], u}}); D[v] = 0; continue; }
    if (D[u]) { ans.push_back({u, {D[u], v}}); D[u] = 0; continue; }
    D[u] = v;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i=1; i<=N; i++) {
    dfs(i);
    dp(i);
  }

  cout << ans.size() << endl;
  for (auto [u, vp]: ans) {
    cout << vp.first << " " << u << " " << vp.second << endl;
  }

  ////////////////////////////////
  return 0;
}
