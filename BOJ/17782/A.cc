#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int n, k;
vector<lld> A;
vector<vector<pll>> tree;

lld dfs(int u) {
  if (tree[u].empty()) return 0;
  for (int i=0; i<tree[u].size(); i++) {
    auto [h, v] = tree[u][i];
    tree[u][i].first = dfs(v);
  }
  sort(tree[u].begin(), tree[u].end());
  return tree[u].back().first + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n >> k;

  A.resize(k);
  tree.resize(n);

  for (int i=0; i<k; i++) cin >> A[i];
  sort(A.begin(), A.end());

  for (int i=1; i<=n-1; i++) {
    int p; cin >> p;
    tree[p].push_back({-1, i});
  }
  dfs(0);

  priority_queue<pll> pq;
  pq.push({tree[0].back().first + 1, 0});
  lld ans = 0;

  while (!pq.empty()) {
    auto [h, u] = pq.top(); pq.pop();

    ans += A.back() * h;
    A.pop_back();

    int v = u;
    while (!tree[v].empty()) {
      int w = tree[v].back().second;
      tree[v].pop_back();

      if (!tree[v].empty()) pq.push({tree[v].back().first + 1, v});
      v = w;
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
