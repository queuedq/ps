#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXL = 105;
lld l, k, D[2][MAXL];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> l >> k;

  D[1][0] = 1;
  lld ans = 0;
  for (int i=1; i<=l; i++) {
    D[0][i] = D[1][i-1];
    D[1][i] = D[0][i-1];
    if (i >= k) D[0][i] += D[1][i-k];
    ans += D[0][i];
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
