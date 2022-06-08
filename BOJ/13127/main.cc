#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
lld N, A[6][MN][MN], B[6][MN][MN], S[6][MN][MN], T[6][MN][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (lld i=1; i<=N; i++) {
    for (lld j=1; j<=N; j++) {
      lld a; cin >> a;
      A[a][i][j] = i*j;
      B[a][i][j] = i*(N-j+1);
    }
  }

  for (lld a: {1, 2, 3, 4, 5}) {
    for (lld i=1; i<=N; i++) {
      for (lld j=1; j<=N; j++)
        S[a][i][j] = S[a][i-1][j] + S[a][i][j-1] - S[a][i-1][j-1] + A[a][i][j];
      for (lld j=N; j>=1; j--)
        T[a][i][j] = T[a][i-1][j] + T[a][i][j+1] - T[a][i-1][j+1] + B[a][i][j];
    }
  }

  lld cnt = N*(N+1)/2;
  cnt *= cnt;
  double ans = 0;

  for (lld a: {1, 2, 3, 4, 5}) {
    for (lld i=1; i<=N; i++) {
      for (lld j=1; j<=N; j++) {
        if (A[a][i][j]) {
          ans += (double)(N-i+1)*(N-j+1) * (S[a][i][j]*2 - A[a][i][j]) * a / cnt; // upper left
          ans += (double)(N-i+1)*j * T[a][i-1][j+1]*2 * a / cnt; // upper right
        }
      }
    }
  }

  cout << fixed << setprecision(8) << ans << endl;

  ////////////////////////////////
  return 0;
}
