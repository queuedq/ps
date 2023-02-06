#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
lld N, A[MN], D[MN];
vector<int> adj[MN];

void dfs(int u) {
  D[u] = A[u];
  for (auto v: adj[u]) {
    dfs(v);
    if (D[v] > 0) D[u] += D[v];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
  }
  for (int i=0; i<N; i++) cin >> A[i];

  dfs(0);
  cout << D[0] << endl;

  ////////////////////////////////
  return 0;
}
