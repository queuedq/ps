#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MX = 305;
const int MN = 1010101;
const int SQRT = 1010;
const lld MOD = 1e9+7;
lld R, S, N, A[MX][MX];
lld D[2][MX][SQRT], E[2][MX][SQRT];
// D[i][j][w] = c : c numbers of path weight w
// E[i][j][m] = c : c numbers of path weights w where m is min {w * m >= N}

lld div_ceil(int a, int b) {
  return a/b + (a%b != 0);
}

void add(lld &res, int c) {
  res = (res + c) % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> R >> S >> N;
  int sN = ceil(sqrt(N));
  int rsN = div_ceil(N, sN);
  for (int i=1; i<=R; i++) {
    for (int j=1; j<=S; j++) cin >> A[i][j];
  }

  D[0][1][1] = 1;

  for (int i=1; i<=R; i++) {
    for (int j=1; j<=S; j++) {
      for (int w=1; w<rsN; w++) D[i&1][j][w] = 0;
      for (int m=1; m<=sN; m++) E[i&1][j][m] = 0;
    }

    for (int j=1; j<=S; j++) {
      for (int w=1; w<rsN; w++) {
        if (w * A[i][j] < rsN) {
          add(D[i&1][j][w * A[i][j]], D[~i&1][j][w]);
          add(D[i&1][j][w * A[i][j]], D[i&1][j-1][w]);
        } else {
          add(E[i&1][j][div_ceil(N, w * A[i][j])], D[~i&1][j][w]);
          add(E[i&1][j][div_ceil(N, w * A[i][j])], D[i&1][j-1][w]);
        }
      }
      
      for (int m=1; m<=sN; m++) {
        add(E[i&1][j][div_ceil(m, A[i][j])], E[~i&1][j][m]);
        add(E[i&1][j][div_ceil(m, A[i][j])], E[i&1][j-1][m]);
      }
    }
  }

  cout << E[R&1][S][1] << endl;

  ////////////////////////////////
  return 0;
}
