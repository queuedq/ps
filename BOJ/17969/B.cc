#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
lld N, leaf[MAXN], p1[MAXN], p2[MAXN];
vector<pll> adj[MAXN];

void dfs(int u, int p, lld &ans) {
  leaf[u] = adj[u].size() == 1;
  
  vector<vector<lld>> sub;
  for (auto [v, l]: adj[u]) {
    if (v == p) continue;
    dfs(v, u, ans);

    leaf[u] += leaf[v];
    lld s1 = p1[v] + l * leaf[v];
    lld s2 = p2[v] + l*l * leaf[v] + 2 * l*p1[v];
    p1[u] += s1;
    p2[u] += s2;
    sub.push_back({leaf[v], s1, s2});
  }

  for (int i=0; i<sub.size(); i++) {
    for (int j=0; j<i; j++) {
      ans += sub[i][2]*sub[j][0]  + sub[j][2]*sub[i][0] + 2 * sub[i][1]*sub[j][1];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;

  for (int i=0; i<N-1; i++) {
    lld a, b, l; cin >> a >> b >> l;
    adj[a].push_back({b, l});
    adj[b].push_back({a, l});
  }

  int root;
  for (root=1; root<=N; root++) {
    if (adj[root].size() == 3) break;
  }

  lld ans = 0;
  dfs(root, 0, ans);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
