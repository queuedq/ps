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
int N, A[MN], indeg[MN], vst[MN];
vector<int> adj[MN];

void dfs(int u, int &size, int &cuts, bool &is_cycle) {
  if (vst[u]) return;
  vst[u] = 1;
  size++;
  cuts += max(indeg[u] - 1, 0);
  is_cycle &= indeg[u] == 1;

  for (auto v: adj[u]) {
    dfs(v, size, cuts, is_cycle);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int u=1; u<=N; u++) {
    cin >> A[u];
    indeg[A[u]]++;
    adj[u].push_back(A[u]);
    adj[A[u]].push_back(u);
  }

  int ans = 0;

  for (int u=1; u<=N; u++) {
    if (vst[u]) continue;
    int size = 0, cuts = 0;
    bool is_cycle = 1;
    dfs(u, size, cuts, is_cycle);

    if (is_cycle && size < N) cuts = 1;
    ans += cuts;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
