#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 105;
const int ML = 1010;
const lld MOD = 1e9+7;
lld N, L, A[MN], D[MN][MN][ML][4];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> L;
  for (int i=1; i<=N; i++) cin >> A[i];
  sort(A+1, A+N+1);
  
  if (N == 1) return cout << 1 << endl, 0;

  D[1][1][0][0] = 1;
  D[1][1][0][1] = 2;
  for (int i=1; i<N; i++) {
    for (int j=1; j<=(N+1)/2; j++) {
      for (int l: {0, 1, 2}) {
        for (int k=0; k<=L; k++) D[i][j][k][l] %= MOD;

        int dk = (A[i+1]-A[i]) * (j*2 - l);

        for (int k=0; k+dk<=L; k++) {
          // merge
          D[i+1][j-1][k+dk][l] += D[i][j][k][l] * (j-1);
          // attach
          D[i+1][j][k+dk][l] += D[i][j][k][l] * (j*2 - l);
          // attach at end
          D[i+1][j][k+dk][l+1] += D[i][j][k][l] * (l==0 ? 2 : 1);
          // new group
          D[i+1][j+1][k+dk][l] += D[i][j][k][l] * (j+1 - l);
          // new group at end
          D[i+1][j+1][k+dk][l+1] += D[i][j][k][l] * (l==0 ? 2 : 1);
        }
      }
    }
  }

  lld ans = 0;
  for (int k=0; k<=L; k++) {
    ans += D[N][1][k][2];
    ans %= MOD;
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
