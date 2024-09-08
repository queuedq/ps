#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
int N, D[MN];
vector<int> adj[MN];
set<pii> E;
vector<pii> ans;

int dfs(int u, int p) {
  D[u] = 1;
  for (auto v: adj[u]) {
    if (v == p) continue;
    D[u] = max(D[u], dfs(v, u) + 1);
  }

  if (D[u] == 5) {
    if (u != 1 && !E.count({1, u})) ans.push_back({1, u});
    D[u] = 0;
  }
  return D[u];
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
    E.insert({u, v});
    E.insert({v, u});
  }

  dfs(1, 0);

  cout << sz(ans) << endl;
  for (auto [u, v]: ans) cout << u << " " << v << endl;

  ////////////////////////////////
  return 0;
}
