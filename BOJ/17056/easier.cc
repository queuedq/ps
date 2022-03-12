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
lld D[2][MX][SQRT*2];
// D[i][j][m] = c : c numbers of path weights w where M[m] is min {w * M[m] >= N}
lld M[MN], id[MN]; // multiplier indexing

lld div_ceil(int a, int b) { return a/b + (a%b != 0); }
void add(lld &res, int c) { res = (res + c) % MOD; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> R >> S >> N;
  for (int i=1; i<=R; i++) {
    for (int j=1; j<=S; j++) cin >> A[i][j];
  }

  int mcnt = 0;
  for (int i=1; i<=N; i++) {
    int m = div_ceil(N, i);
    if (id[m] == 0) {
      id[m] = ++mcnt;
      M[mcnt] = m;
    }
  }

  D[0][1][1] = 1;

  for (int i=1; i<=R; i++) {
    for (int j=1; j<=S; j++) {
      for (int m=1; m<=mcnt; m++) D[i&1][j][m] = 0;
    }

    for (int j=1; j<=S; j++) {
      for (int m=1; m<=mcnt; m++) {
        add(D[i&1][j][id[div_ceil(M[m], A[i][j])]], D[~i&1][j][m]);
        add(D[i&1][j][id[div_ceil(M[m], A[i][j])]], D[i&1][j-1][m]);
      }
    }
  }

  cout << D[R&1][S][mcnt] << endl;

  ////////////////////////////////
  return 0;
}
