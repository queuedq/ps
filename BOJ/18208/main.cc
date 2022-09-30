#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;
const int MN = 5050;
lld N, M, D[MN][MN], same[MN], diff[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  fill(diff, diff+N+1, -1);
  for (int i=1; i<=M; i++) {
    lld l, r; string s; cin >> l >> r >> s;
    if (s == "same") { same[l]++, same[r]--; }
    else {
      if (l == r) { cout << 0 << endl; return 0; } // impossible
      diff[r] = max(diff[r], l);
    }
  }

  // D[i][j]: fill [1, i], last diff at j (ans[j-1] != ans[j])
  D[0][0] = 1;
  int same_cnt = 0;
  for (int i=1; i<=N; i++) {
    for (int j=0; j<i; j++) {
      // if possible to fill same
      if (diff[i] < j) D[i][j] = (D[i][j] + D[i-1][j]) % MOD;
    }
    for (int j=0; j<i; j++) {
      // if possible to fill diff
      if (same_cnt == 0) D[i][i] = (D[i][i] + D[i-1][j]) % MOD;
    }
    same_cnt += same[i];
  }

  lld ans = 0;
  for (int j=0; j<=N; j++) ans = (ans + D[N][j]) % MOD;
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
