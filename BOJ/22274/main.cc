#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;
const int MK = 755;
const int MN = 10101;
lld K, L, T[MK][MK], N, P[MN], D[MN][MK], E[MN][MK];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> K >> L;
  for (int i=1; i<=K; i++) {
    for (int j=1; j<=K; j++) cin >> T[i][j];
  }
  cin >> N;
  for (int i=N-1; i>=1; i--) cin >> P[i];

  for (int j=1; j<=K; j++) D[1][j] = 1;
  for (int j=1; j<=K; j++) E[1][j] = (E[1][j-1] + D[1][j]) % MOD;

  for (int i=2; i<=N; i++) {
    for (int j=1; j<=K; j++) {
      int l = lower_bound(T[j]+1, T[j]+K+1, P[i-1]-L) - T[j];
      int r = upper_bound(T[j]+1, T[j]+K+1, P[i-1]+L) - T[j] - 1;
      D[i][j] = (E[i-1][r] - E[i-1][l-1]) % MOD;
      D[i][j] = (D[i][j] + MOD) % MOD;
    }
    for (int j=1; j<=K; j++) E[i][j] = (E[i][j-1] + D[i][j]) % MOD;
  }

  cout << E[N][K] << endl;

  ////////////////////////////////
  return 0;
}
