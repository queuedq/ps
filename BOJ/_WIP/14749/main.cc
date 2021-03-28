#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;
int N, s, t, cnt, in[MN], out[MN];
vector<int> adj[MN];

void dfs(int u, int p) {
  in[u] = cnt++;
  auto it = find(begin(adj[u]), end(adj[u]), p);
  if (it != end(adj[u])) adj[u].erase(it);
  for (auto v: adj[u]) dfs(v, u);
  out[u] = cnt++;
}

bool ancestor(int u, int v) {
  return in[u] <= in[v] && out[v] <= out[u];
}

vector<int> solve(int s, int t) {
  vector<int> ans = {s};
  if (s == t) return ans;
  int v; // ancestor of t

  for (auto u: adj[s]) {
    if (ancestor(u, t)) { v = u; continue; }

    auto sub = solve(u, adj[u].empty() ? u : adj[u][0]);
    reverse(begin(sub), end(sub));
    ans.insert(end(ans), begin(sub), end(sub));
  }

  if (v == t) {
    auto sub = solve(t, adj[t].empty() ? t : adj[t][0]);
    reverse(begin(sub), end(sub));
    ans.insert(end(ans), begin(sub), end(sub));
  } else {
    auto sub = solve(v, t);
    ans.insert(end(ans), begin(sub), end(sub));
  }

  return ans;
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

  auto ans = solve(s, t);
  for (auto a: ans) cout << a << endl;

  ////////////////////////////////
  return 0;
}
