#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505;
const int MOD = 1000;
int N, x[MN], d[MN], b[MN], D[MN][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    cin >> x[i] >> d[i] >> b[i];
  }

  D[1][1] = 1;
  for (int i=2; i<=N; i++) {
    for (int j=1; j<i; j++) {
      for (int k=1; k<i; k++) {
        if (x[k] + d[k] >= x[i]) D[i][j] += D[k][j];
        if (b[i] && x[i] - d[i] <= x[k]) D[j][i] += D[j][k];
        D[i][j] %= MOD;
        D[j][i] %= MOD;
      }
    }
  }

  lld ans = 0;
  for (int k=1; k<N; k++) {
    if (x[N] - d[N] <= x[k]) ans = (ans + D[N][k]) % MOD;
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
