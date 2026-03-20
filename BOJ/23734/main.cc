#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 2e18;
const int MN = 100'001;
lld N, K, L[MN], R[MN], cnt[MN];

lld dfs(int u) {
  if (!u) return 0;
  return cnt[u] = min(dfs(L[u])*2 + dfs(R[u]) + 1, INF);
}

int ans(int u, lld i) {
  if (i == 1) return u;
  i--;
  if (i <= cnt[L[u]]) return ans(L[u], i);
  i -= cnt[L[u]];
  if (i <= cnt[L[u]]) return ans(L[u], i);
  i -= cnt[L[u]];
  if (i <= cnt[R[u]]) return ans(R[u], i);
  return -1; // unreachable
}

int main() {
  cin >> N >> K;
  for (int i=1; i<=N; i++) cin >> L[i] >> R[i];
  dfs(1);
  cout << ans(1, K) << endl;
  return 0;
}
