#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> adj[50001];

int dfs(int u, int p) {
  int res = 0;
  for (auto v: adj[u]) {
    if (v == p) continue;
    res |= dfs(v, u);
  }
  return res + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  int res = dfs(1, 0), ans = 0;
  while (1 << ans <= res) ans++;
  cout << ans - 1 << endl;

  return 0;
}
