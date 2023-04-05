#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 605;
const int O = MN*2;
lld N, K, A[MN*5][MN*5], D[2][MN*5][MN*5], E[2][MN*5][MN*5];
// \     /
//  o   o

// ...  .
//  o  .o.

void solve(int test) {
  cin >> N >> K;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cin >> A[O+i][O+j];
    }
  }

  for (int i=0; i<N+K; i++) {
    for (int j=-K; j<N+K; j++) {
      D[0][O+i][O+j] = D[0][O+i-1][O+j-1] + A[O+i][O+j] - A[O+i-K][O+j-K];
      D[1][O+i][O+j] = D[1][O+i-1][O+j+1] + A[O+i][O+j] - A[O+i-K][O+j+K];
    }
  }

  for (int i=0; i<N+K; i++) {
    for (int j=-K; j<N+K; j++) {
      E[0][O+i][O+j] = E[0][O+i][O+j-1] + D[1][O+i][O+j] - D[0][O+i][O+j-1];
      E[1][O+i][O+j] = E[1][O+i][O+j-1] + D[0][O+i][O+j+K-1] - D[1][O+i][O+j-K];
    }
  }

  lld ans = 0;
  for (int j=-K; j<N+K; j++) {
    lld X = 0;
    for (int i=-K; i<N+K; i++) {
      X = X + E[0][O+i+K-1][O+j] - E[1][O+i-1][O+j];
      ans = max(ans, X);
    }
  }

  // cleanup
  for (int i=0; i<N+K; i++) {
    for (int j=-K; j<N+K; j++) {
      A[O+i][O+j] = 0;
      D[0][O+i][O+j] = D[1][O+i][O+j] = 0;
      E[0][O+i][O+j] = E[1][O+i][O+j] = 0;
    }
  }

  cout << "Case #" << test << endl;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
