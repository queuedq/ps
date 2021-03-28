#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 21;
const int MOD = 100'000;
int M, N, mask, D[2][1<<MN][2]; // filled, JO state, end with J
char A[MN][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> M >> N;
  mask = (1<<N) - 1;

  int total = 1;
  for (int i=0; i<M; i++) {
    for (int j=0; j<N; j++) {
      cin >> A[i][j];
      if (A[i][j] == '?') total = total*3 % MOD;
    }
  }

  for (int state = 0; state < 1<<N; state ++) {
    for (int J = 0; J < 2; J++) D[M*N & 1][state][J] = 1;
  }

  for (int i = M*N-1; i >= 0; i--) {
    for (int state = 0; state < 1<<N; state++) {
      for (int J = 0; J < 2; J++) {
        int r = i/N, c = i%N;
        D[i&1][state][J] = 0;

        if (A[r][c] == 'J' || A[r][c] == '?') {
          D[i&1][state][J] += D[~i&1][state<<1 & mask][1];
        }

        if (A[r][c] == 'O' || A[r][c] == '?') {
          D[i&1][state][J] += D[~i&1][state<<1 & mask | J][0];
        }

        if (A[r][c] == 'I' || A[r][c] == '?') {
          if (c == N-1 || (state>>N-2 & 1) == 0) {
            D[i&1][state][J] += D[~i&1][state<<1 & mask][0];
          }
        }

        D[i&1][state][J] = D[i&1][state][J] % MOD;
      }
    }
  }

  cout << (total - D[0][0][0] + MOD) % MOD << endl;

  ////////////////////////////////
  return 0;
}
