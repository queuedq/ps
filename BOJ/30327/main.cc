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
const int MN = 105;
int N, X[MN*2], cnt[MN];
lld D[MN*2][MN][MN][2];
// D[i][j][k][b]: until ith place, j: unpaired unused, k: unpaired single, b: is last unpaired?

void add(lld &x, lld y) { x = (x+y) % MOD; }

void solve() {
  int N; cin >> N;
  for (int i=1; i<=N; i++) cnt[i] = 0;
  for (int i=1; i<=N*2; i++) {
    cin >> X[i];
    if (X[i]) cnt[X[i]]++;
  }

  memset(***D, 0, (MN*2)*MN*MN*2);
  D[0][0][0][0] = 1;

  for (int i=1; i<=N*2; i++) {
    for (int j=0; j<=min(i, N); j++) {
      for (int k=0; k<=min(i, N); k++) {
        lld &D0 = D[i][j][k][0] = 0;
        lld &D1 = D[i][j][k][1] = 0;
        
        if (cnt[X[i]] == 0) {
          add(D0, D[i-1][j+1][k][0] * (j+1));
          add(D0, D[i-1][j][k+1][0] * (k+1));
          add(D0, D[i-1][j+1][k][1] * (j+1 - (cnt[X[i-1]] == 0)));
          add(D0, D[i-1][j][k+1][1] * (k+1 - (cnt[X[i-1]] == 1)));

          if (j-1 >= 0) add(D1, D[i-1][j-1][k][0] + D[i-1][j-1][k][1]);

        } else if (cnt[X[i]] == 1) {
          add(D0, D[i-1][j+1][k][0] * (j+1));
          add(D0, D[i-1][j+1][k][1] * (j+1 - (cnt[X[i-1]] == 0)));

          if (k-1 >= 0) add(D1, D[i-1][j][k-1][0] + D[i-1][j][k-1][1]);

        } else {
          add(D0, D[i-1][j][k][0] + D[i-1][j][k][1]);
        }
      }
    }
  }

  lld P = 0;
  for (int i=1; i<=N; i++) P += (cnt[i] == 0);

  lld ans = D[N*2][0][0][0];
  for (int i=1; i<=P; i++) ans = (ans * i) % MOD;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
