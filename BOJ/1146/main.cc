#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MOD = 1'000'000;
const int MN = 105;
int N, D[MN][MN];
// D: zig-zag perm starting with <=k, up first

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  if (N == 1) { cout << 1 << endl; return 0; }

  D[0][0] = 1;
  for (int i=1; i<=N; i++) {
    for (int k=1; k<=i; k++) D[i][k] = (D[i][k-1] + D[i-1][i-k]) % MOD;
  }
  cout << (D[N][N] * 2) % MOD << endl;

  ////////////////////////////////
  return 0;
}
