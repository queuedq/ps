#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 3030;
const lld MOD = 1e9+7;
lld N, K, L[MN], D[MN][MN], X[MN];
char A[MN];

// D[k][i]: ways to place k hints in cells 1..i

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=K; i++) cin >> L[i];
  cin >> (A+1);

  int last = 0; // last X pos
  for (int i=1; i<=N; i++) {
    if (A[i] == 'X') last = i;
    X[i] = last;
  }

  // zero hints
  D[0][0] = 1;
  for (int i=1; i<=N; i++) {
    if (A[i] != 'O') D[0][i] = D[0][i-1];
  }

  // DP
  for (int k=1; k<=K; k++) {
    for (int i=1; i<=N; i++) {
      if (A[i] != 'O') D[k][i] = D[k][i-1]; // not place hint
      if (i-L[k] >= X[i] && A[i-L[k]] != 'O') { // place hint
        D[k][i] = (D[k][i] + D[k-1][max(i-L[k]-1, 0LL)]) % MOD;
      }
    }
  }

  cout << D[K][N] << endl;

  ////////////////////////////////
  return 0;
}
