#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, K, D[MN], cnt;
vector<int> adj[MN];

void dfs(int u, int p) {
  int mn = MN, mx = -MN;
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    mn = min(mn, D[v]+1);
    mx = max(mx, D[v]+1);
  }

  // cout << D[u] << endl;

  if (mx == -MN) {
    D[u] = 0;
    return;
  }
  D[u] = mx;
  if (-mn-1 >= mx) D[u] = mn;

  if (D[u] == K) {
    cnt++;
    D[u] = -K-1;
    // cout << u << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0);
  if (D[1] >= 0) cnt++;

  // for (int i=1; i<=N; i++) cout << i << ": " << D[i] << endl;
  cout << cnt << endl;

  ////////////////////////////////
  return 0;
}
