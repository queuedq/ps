#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;
int n, k, ans;
vector<int> adj[MN];
bool A[MN];

bool dfs(int u, int p) {
  bool res = A[u];
  for (auto v: adj[u]) {
    if (v == p) continue;
    res |= dfs(v, u);
  }
  if (res) ans++;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n >> k;
  for (int i=0; i<n-1; i++) {
    int a, b, w; cin >> a >> b >> w;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int root = 0;
  for (int i=0; i<k; i++) {
    int a; cin >> a;
    A[a] = true;
    root = a;
  }

  dfs(root, 0);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
