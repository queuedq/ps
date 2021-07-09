#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MOD = 1e8+7;
int n, m, vst[101];
vector<int> adj[101];

int pow2(int e) {
  int res = 1;
  for (int i=0; i<e; i++) res = res * 2 % MOD;
  return res;
}

void dfs(int u, int &cnt) {
  if (vst[u]) return;
  vst[u] = true;
  cnt++;
  for (auto v: adj[u]) dfs(v, cnt);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n >> m;
  for (int i=0; i<m; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  bool ok = true;
  int comp = 0;
  for (int i=1; i<=n; i++) {
    if (!vst[i]) {
      int cnt = 0;
      dfs(i, cnt);
      if (cnt%2 != 0) ok = false;
      comp++;
    }
  }

  if (ok) cout << pow2(m-n+comp) << endl;
  else cout << 0 << endl;

  ////////////////////////////////
  return 0;
}
