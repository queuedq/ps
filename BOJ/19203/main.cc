#include <bits/stdc++.h>
#include <sys/signal.h>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
int N, C[MN], cnt[MN];
vector<int> adj[MN];

int dfs(int u, int p) {
  int lca = 0;
  cnt[u] = 0;
  for (auto v: adj[u]) {
    if (v == p) continue;
    int t = dfs(v, u);
    if (t) lca = t;
    cnt[u] += cnt[v];
  }
  if (C[u] != 0) cnt[u] = 1;

  if (!lca && cnt[u] >= 2) lca = u;
  return lca;
}

int valid_color(int u) {
  int used[5] = {};
  for (auto v: adj[u]) used[C[v]] = 1;
  for (int c=1; c<=4; c++) {
    if (!used[c]) return C[u] = c;
  }
  assert(0);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  C[1] = 1;
  cout << "1 1" << endl;

  while (1) {
    int u, c; cin >> u >> c;
    if (u == -1) break;
    C[u] = c;

    int lca = dfs(1, 0); // find 3-color component

    if (lca) {
      // break 3-color component
      cout << lca << " " << valid_color(lca) << endl;
    } else {
      int u; // uncolored adj to colored
      for (u=1; u<=N; u++) {
        if (C[u]) continue;
        bool ok = 0;
        for (auto v: adj[u]) { if (C[v]) ok = 1; }
        if (ok) break;
      }
      cout << u << " " << valid_color(u) << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
