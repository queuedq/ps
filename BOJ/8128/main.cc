#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
int N, L, cnt[MN]; // path lengths
vector<int> adj[MN];

pii farthest(int u, int p, int d) {
  pii ret = {d, u};
  for (auto v: adj[u]) {
    if (v == p) continue;
    ret = max(ret, farthest(v, u, d+1));
  }
  return ret;
}

int dfs(int u, int p) { // returns max length
  int mx = 0;
  for (auto v: adj[u]) {
    if (v == p) continue;
    mx = max(mx, dfs(v, u));
  }

  if (mx > 0) cnt[mx]--;
  cnt[mx+1]++;
  return mx + 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> L;
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  int root = farthest(1, 0, 0).second;
  dfs(root, 0);

  L = L*2 - 1;
  int ans = 0;
  for (int i=N; i>=1; i--) {
    while (cnt[i] > 0 && L > 0) { ans += i; cnt[i]--; L--; }
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
