#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
const int RT = 500;
const lld MOD = 1e9+7;
lld D[RT][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  D[0][0] = 1;
  for (int i=1; i<RT; i++) {
    for (int j=0; j<MN; j++) {
      D[i][j] = D[i-1][j] + (j-i >= 0 ? D[i-1][j-i] : 0);
      D[i][j] %= MOD;
    }
  }

  for (int i=1; i<RT; i++) {
    for (int j=1; j<MN; j++) {
      D[i][j] += D[i][j-1];
      D[i][j] %= MOD;
    }
  }

  int T; cin >> T;
  while (T--) {
    lld a, b; cin >> a >> b;
    
    lld ans = 0;
    for (int i=1; i*(i+1)/2 <= a+b; i++) {
      lld sum = i*(i+1)/2;
      if (sum-b-1 >= 0) ans += D[i][a] - D[i][sum-b-1];
      else ans += D[i][a];
      ans = (ans%MOD+MOD) % MOD;
    }
    cout << ans << endl;
  }  

  ////////////////////////////////
  return 0;
}
