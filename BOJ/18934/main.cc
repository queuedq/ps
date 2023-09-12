#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 5050;
lld N, MOD, D[MN][5];
// D[i][g]: partitioning i-sized perm into g groups
// we need special care for g = 2, 3
// no need to distinguish g >= 4

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> MOD;
  D[1][1] = 1;
  for (int i=2; i<=N; i++) {
    for (int j=1; j<i; j++) {
      D[i][2] = (D[i][2] + D[i-j][1] * D[j][1]) % MOD;
      D[i][3] = (D[i][3] + D[i-j][2] * D[j][1]) % MOD;
      D[i][4] = (D[i][4] + D[i-j][3] * D[j][1]) % MOD;
      D[i][4] = (D[i][4] + D[i-j][4] * D[j][1]) % MOD;
    }
    D[i][1] = (D[i][2] + D[i][3] + D[i][4] * 2) % MOD;
  }

  for (int i=1; i<=N; i++) cout << D[i][1] << endl;

  ////////////////////////////////
  return 0;
}
