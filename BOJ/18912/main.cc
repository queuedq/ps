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
int N, vst[MN], comp[MN];
vector<pii> adj[MN];

int dfs(int u, int p, int x, int c) {
  int s = 1;
  vst[u] = 1;
  comp[u] = c;
  for (auto [v, w]: adj[u]) {
    if (v == p || w >= x) continue;
    s += dfs(v, u, x, c);
  }
  return s;
}

// w: edge weight to disconnect
// c: current comp
// cs: comp size
// k: # moves left
lld solve(int w, int c, int cs, int k) {
  // get sub components
  fill(vst+1, vst+N+1, 0);
  vector<pii> sub; // (size, node)
  for (int u=1; u<=N; u++) {
    if (vst[u] || comp[u] != c) continue; // only visit comp c
    int s = dfs(u, 0, w, u);
    sub.push_back({s, u});
  }
  sort(all(sub));
  reverse(all(sub));

  // greedy
  auto [ls, lc] = sub[0]; // largest comp
  int rest = cs - ls; // tot sub comps except the largest
  if (k <= rest * 2) return (1LL<<w) * k;
  return (1LL<<w) * rest * 2 + solve(w-1, lc, ls, k - rest*2);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  fill(comp+1, comp+N+1, 1); // init single component
  cout << solve(30, 1, N, N-1) << endl;

  ////////////////////////////////
  return 0;
}
