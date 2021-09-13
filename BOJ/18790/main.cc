#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505;
int N, A[2*MN];
bool D[2*MN][MN][MN], E[2*MN][MN][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=2*N-1; i++) cin >> A[i];

  D[0][0][0] = 1;
  for (int i=1; i<=2*N-1; i++) {
    D[i][0][0] = 1;
    for (int j=1; j<=N; j++) {
      for (int k=0; k<N; k++) {
        if (D[i-1][j][k]) {
          D[i][j][k] = 1;
          E[i][j][k] = 0;
        } else if (D[i-1][j-1][(k-A[i] + N) % N]) {
          D[i][j][k] = 1;
          E[i][j][k] = 1;
        }
      }
    }
  }

  if (!D[2*N-1][N][0]) { cout << -1; return 0; }

  int j = N, k = 0;
  for (int i=2*N-1; i>0; i--) {
    if (E[i][j][k]) {
      cout << A[i] << " ";
      j--;
      k = (k-A[i] + N) % N;
    }
  }

  ////////////////////////////////
  return 0;
}
