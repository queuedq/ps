#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MOD = 1e8;
int M, N, A[150], D[150][1<<12];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> M >> N;
  for (int i=0; i<M*N; i++) cin >> A[i];

  fill(D[M*N], D[M*N] + (1<<12), 1);

  for (int i=M*N-1; i>=0; i--) {
    for (int m=0; m<1<<N; m++) {
      D[i][m] = D[i+1][m>>1];
      if (A[i] && !(m&1) && (i%N == 0 || !(m>>(N-1)&1)))
        D[i][m] += D[i+1][m>>1 | 1<<(N-1)];

      D[i][m] %= MOD;
    }
  }

  cout << D[0][0] << endl;

  ////////////////////////////////
  return 0;
}
