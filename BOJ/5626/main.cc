#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 10101;
const lld MOD = 1e9+7;
lld N, h[MN], D[2][MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> h[i];

  if (h[0] > 0) { cout << 0 << endl; return 0; }
  D[0][0] = 1;

  for (int i=1; i<N; i++) {
    int i1 = (i-1)&1;
    fill(D[i&1], D[i&1]+i+1, 0);

    for (int j=0; j<=i; j++) {
      if (h[i] == -1 || h[i] == j) {
        if (j > 0) D[i&1][j] += D[i1][j-1];
        D[i&1][j] += D[i1][j];
        D[i&1][j] += D[i1][j+1];
        D[i&1][j] %= MOD;
      }
    }
  }

  cout << D[(N-1)&1][0] << endl;

  ////////////////////////////////
  return 0;
}
