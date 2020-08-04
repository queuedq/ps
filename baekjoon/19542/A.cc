#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, S, D, height[MAXN], cnt;
vector<int> adj[MAXN];

void dfs(int u, int p) {
  height[u] = 0;
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    height[u] = max(height[u], height[v]+1);
  }
  if (height[u] >= D || u == S) cnt++;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> S >> D;
  for (int i=0; i<N-1; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(S, 0);
  cout << (cnt-1) * 2 << endl;

  ////////////////////////////////
  return 0;
}
