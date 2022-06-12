#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, M, dfn[MN], vst[MN], up[MN], down[MN], idx, ans=1;
vector<int> adj[MN];

void dfs1(int u, int p) {
  dfn[u] = ++idx;

  for (auto v: adj[u]) {
    if (v == p) continue;
    if (dfn[v]) {
      if (dfn[v] < dfn[u]) { up[u]++; down[v]++; } // back edge
      continue;
    }
    dfs1(v, u);
  }
}

int dfs2(int u) {
  vst[u] = 1;
  int cnt = up[u]; // back edge count
  for (auto v: adj[u]) {
    if (!vst[v]) cnt += dfs2(v);
  }
  if (cnt > 1) ans = 0;
  return cnt - down[u];
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
  dfs1(1, 0);
  dfs2(1);
  cout << (ans ? "Cactus" : "Not cactus") << endl;

  ////////////////////////////////
  return 0;
}
