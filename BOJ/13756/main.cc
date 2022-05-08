#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;
lld K, D[32][32][2];
// make RREF
// D[i][j][b]
// i: current bit
// j: number of rows
// b: same as k up to ith bit (rev. order)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> K;
  D[31][0][1] = 1;
  for (int i=30; i>=0; i--) {
    if (K < 1<<i) D[i][0][1] = 1;
    else D[i][0][0] = 1;
    
    for (int j=1; j<32; j++) {
      D[i][j][0] = (D[i+1][j][0] << j) + D[i+1][j-1][0];
      if (K>>i & 1) D[i][j][0] += D[i+1][j][1] << (j-1);
      D[i][j][0] %= MOD;

      D[i][j][1] = D[i+1][j][1] << (j-1);
      if (K>>i & 1) D[i][j][1] += D[i+1][j-1][1];
      D[i][j][1] %= MOD;
    }
  }

  lld ans = 0;
  for (int j=0; j<32; j++) ans = (ans + D[0][j][0] + D[0][j][1]) % MOD;
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
