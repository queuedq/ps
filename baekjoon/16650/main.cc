#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MOD = 998'244'353;
const int MAXN = 2e5+5;
const int SQRT = 500;
int D[MAXN][SQRT];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  D[1][1] = 1;
  for (int i=3; i<MAXN; i++) {
    int j;
    for (j=1; j*j<=i; j++) {
      D[i][j] = D[i-2*j][j];
      if (j*j == i) D[i][j] = 1;
    }
    for (; j>=1; j--) {
      D[i][j] = (D[i][j+1] + D[i][j]) % MOD;
    }
  }

  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    cout << D[N][1] << endl;
  }

  ////////////////////////////////
  return 0;
}
