#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 10101;
int N, A[MN], cnt[MN], sum[MN];
vector<int> adj[MN];

void dfs(int u, int p) {
  cnt[u] = 1;
  sum[u] = A[u];
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    cnt[u] += cnt[v];
    sum[u] += sum[v];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  while (1) {
    cin >> N;
    if (N == 0) break;

    for (int i=1; i<=N; i++) {
      int u, k; cin >> u >> A[u] >> k;
      while (k--) { 
        int v; cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
    }

    dfs(1, 0);

    lld ans = 0;
    for (int i=1; i<=N; i++) ans += abs(cnt[i] - sum[i]);
    cout << ans << endl;

    for (int i=1; i<=N; i++) adj[i].clear();
  }

  ////////////////////////////////
  return 0;
}
