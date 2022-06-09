#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;
int N, s, t, cnt, in[MN], out[MN], sz[MN], idx, ans[MN];
vector<int> adj[MN];

void dfs(int u, int p) {
  in[u] = cnt++;
  sz[u] = 1;

  if (p != 0) { // remove p from adj[u]
    auto it = find(begin(adj[u]), end(adj[u]), p);
    adj[u].erase(it);
  }
  for (auto v: adj[u]) {
    dfs(v, u);
    sz[u] += sz[v];
  }

  out[u] = cnt++;
}

bool ancestor(int u, int v) {
  return in[u] <= in[v] && out[v] <= out[u];
}

void solve(int s, int t, int a, int b, int d) { // fill ans[a:b] with direction d
  ans[a] = s;
  if (s == t) return;
  int i = a+d;

  int v = -1; // next node on s-t path
  for (auto u: adj[s]) {
    if (ancestor(u, t)) { v = u; continue; }
    solve(u, (adj[u].empty() ? u : adj[u][0]), i+(sz[u]-1)*d, i, -d);
    i += sz[u]*d;
  }

  if (v == t) solve(t, (adj[t].empty() ? t : adj[t][0]), b, i, -d);
  else solve(v, t, i, b, d);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cin >> s >> t;

  dfs(s, 0);

  solve(s, t, 0, N-1, 1);
  for (int i=0; i<N; i++) cout << ans[i] << endl;

  ////////////////////////////////
  return 0;
}
