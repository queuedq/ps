#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
int N;
double L, R;
double D[2][MAXN][MAXN*2]; // length (toggle), rightmost, current

void solve() {
  cin >> N >> L >> R;
  D[0][0][MAXN+0] = 1;
  for (int l=0; l<N; l++) {
    for (int i=0; i<=l+1; i++) {
      for (int j=-l-1; j<=l+1; j++) D[~l&1][i][MAXN+j] = 0;
    }

    for (int i=0; i<=l; i++) {
      for (int j=-l; j<=l; j++) {
        D[~l&1][i][MAXN+j-1] += D[l&1][i][MAXN+j] * L;
        D[~l&1][max(i, j+1)][MAXN+j+1] += D[l&1][i][MAXN+j] * R;
        D[~l&1][i][MAXN+j] += D[l&1][i][MAXN+j] * (1-L-R);
      }
    }
  }

  double ans = 0;
  for (int i=0; i<=N; i++) {
    for (int j=-N; j<=N; j++) {
      ans += i * D[N&1][i][MAXN+j];
    }
  }

  cout << fixed << setprecision(4) << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
