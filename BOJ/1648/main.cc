#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MOD = 9901;
const int MN = 15;
int N, M, D[MN*MN][1<<MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  D[N*M][0] = 1;

  for (int i=N*M-1; i>=0; i--) {
    for (int state = 0; state < 1<<M; state++) {
      if (state & 1) // occupied
        D[i][state] += D[i+1][state >> 1];

      if ((state & 1) == 0) // vertical
        D[i][state] += D[i+1][state >> 1 | 1 << M-1];

      if (i%M != M-1 && (state & 3) == 0) // horizontal
        D[i][state] += D[i+1][state >> 1 | 1];

      D[i][state] %= MOD;
    }
  }
  
  cout << D[0][0] << endl;

  ////////////////////////////////
  return 0;
}
