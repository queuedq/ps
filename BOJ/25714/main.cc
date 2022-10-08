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
const int MN = 305;
lld N, D[MN][4]; // D[i][k] -- i floors, k components

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  D[3][1] = 1; // 3
  D[3][2] = 2; // 1 2 / 2 1
  D[3][3] = 1; // 1 1 1
  for (int i=4; i<=N-1; i++) {
    // add to end or merge
    D[i][1] = (D[i-1][1] * 2 + D[i-1][2]) % MOD;
    D[i][2] = (D[i-1][2] * 4 + D[i-1][3] * 2) % MOD;
    D[i][3] = (D[i-1][3] * 6) % MOD;
  }
  cout << (D[N-1][1] * N) % MOD << endl;

  ////////////////////////////////
  return 0;
}
