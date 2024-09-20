#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
int N, M, vst[MN], path[MN], vn;
vector<int> adj[MN];
// back edge span info
// lo: lower end node (= edge) / hi_v: higher end node / hi_e: higher end edge
// span: back edge that spans "this edge's parent node"
int lo[MN], hi_v[MN], hi_e[MN], span[MN];
lld ans;

void dfs(int u, int p) {
  vst[u] = ++vn;
  int span_cnt = 0;
  bool ok = 1;

  for (auto v: adj[u]) {
    if (v == p) continue;
    if (vst[v]) {
      if (vst[v] < vst[u]) { // back edge
        lo[u]++;
        hi_v[v]++;
        hi_e[path[v]]++;
      }
      continue;
    }

    path[u] = v;
    dfs(v, u);

    span_cnt += span[v];
    ok &= span[v] <= 1;
  }

  span[u] = span_cnt + lo[u] - hi_e[u];
  ok &= (N-1) + span_cnt + lo[u] + hi_v[u] == M;
  if (ok) ans += u;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
