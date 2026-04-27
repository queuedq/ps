#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
const lld INF = 1e18;
int N, M;
lld D[MN];
vector<pii> adj[MN];

bool solve(int k) { // is ans >= k?
  D[N] = 0;
  for (int u=N-1; u>=1; u--) {
    D[u] = INF;
    for (auto [v, i]: adj[u]) {
      if (i < k) D[u] = min(D[u], D[v] - 1);
      else if (i < k+20) D[u] = min(D[u], D[v] + (1<<(i-k)) - 1);
    }
  }
  return D[1] >= 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=M; i++) {
    int u, v; cin >> u >> v; // u < v
    adj[u].push_back({v, i});
  }

  int l = 0, r = M+1;
  while (l+1 < r) {
    int m = (l+r)/2;
    if (solve(m)) l = m;
    else r = m;
  }

  cout << l << endl;

  ////////////////////////////////
  return 0;
}
