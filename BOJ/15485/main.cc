#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;
const int MAXN = 1'000'005;
lld D[3][MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  string S; cin >> S;

  for (int i=1; i<=S.size(); i++) {
    D[0][i] = D[0][i-1];
    D[1][i] = D[1][i-1];
    D[2][i] = D[2][i-1];
    if (S[i-1] == 'a') {
      D[0][i] = (D[0][i-1]*2 + 1) % MOD;
    } else if (S[i-1] == 'b') {
      D[1][i] = (D[1][i-1]*2 + D[0][i-1]) % MOD;
    } else {
      D[2][i] = (D[2][i-1]*2 + D[1][i-1]) % MOD;
    }
  }

  cout << D[2][S.size()] << endl;

  ////////////////////////////////
  return 0;
}
