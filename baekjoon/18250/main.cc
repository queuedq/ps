#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
vector<bool> oddDeg;
vector<vector<int>> conn;

struct DSU {
  vector<int> parent, size;

  DSU(int s) {
    parent.resize(s); size.resize(s);
    for (int i = 0; i < s; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
  }

  void merge(int x, int y) {
    x = find(x); y = find(y);
    if (size[x] < size[y]) swap(x, y);
    parent[y] = x;
    size[x] += size[y];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int n, m; cin >> n >> m;
  oddDeg.resize(n+1);
  conn.resize(n+1);
  DSU dsu(n+1);
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    dsu.merge(u, v);
    oddDeg[u] = !oddDeg[u];
    oddDeg[v] = !oddDeg[v];
  }

  for (int i = 1; i <= n; i++) {
    conn[dsu.find(i)].push_back(i);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int oddTot = 0;
    for (int node: conn[i]) {
      oddTot += oddDeg[node];
    }
    if (conn[i].size() > 1 && oddTot == 0) ans++;
    else ans += oddTot / 2;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
