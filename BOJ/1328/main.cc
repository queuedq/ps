#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;
const int MN = 105;
lld N, L, R, comb[MN][MN], D[MN][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> L >> R;

  comb[0][0] = 1;
  for (int i=1; i<=N-1; i++) {
    comb[i][0] = 1;
    for (int j=1; j<=i; j++) comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
  }

  D[0][0] = 1;
  for (int i=1; i<=N-1; i++) {
    D[i][0] = 0;
    for (int j=1; j<=i; j++) D[i][j] = (D[i-1][j-1] + D[i-1][j] * (i-1)) % MOD;
  }

  lld ans = 0;
  for (int i=0; i<=N-1; i++) {
    ans += (D[i][L-1] * D[N-1-i][R-1]) % MOD * comb[N-1][i];
    ans %= MOD;
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
