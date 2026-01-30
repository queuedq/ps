#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 1e18;
lld N, A[1<<20], B[1<<20], D[1<<20];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<1<<N; i++) cin >> A[i];
  for (int i=0; i<1<<N; i++) cin >> B[i];

  // SOS DP
  for (int i=0; i<N; i++) {
    for (int m=0; m<(1<<N); m++) {
      if (m>>i & 1) {
        A[m] += A[m ^ 1<<i];
        B[m] += B[m ^ 1<<i];
      }
    }
  }

  // DP
  // When {1, 2, ..., N} is colored red,
  // there exists i s.t. all subsets including i are colored red.
  // Otherwise, there exists a blue subset including each i
  // which implies their union {1, 2, ..., N} must be colored blue.
  D[0] = min(A[0], B[0]);

  for (int m=1; m<(1<<N); m++) {
    D[m] = INF;
    for (int i=0; i<N; i++) {
      if (m>>i & 1) {
        lld val = min(A[m] - A[m ^ 1<<i], B[m] - B[m ^ 1<<i]);
        D[m] = min(D[m], D[m^(1<<i)] + val);
      }
    }
  }

  cout << D[(1<<N)-1] << endl;

  ////////////////////////////////
  return 0;
}
