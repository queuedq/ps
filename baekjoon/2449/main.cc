#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 201, MAX_K = 21;
int N, K;
int A[MAX_N];
int D[MAX_N][MAX_N][MAX_K];

void dp() {
  for (int i = 1; i <= N; i++) {
    for (int k = 1; k <= K; k++) {
      D[i][i][k] = (k != A[i]);
    }
  }

  for (int len = 2; len <= N; len++) {
    for (int i = 1; i <= N - len + 1; i++) {
      int j = i + len - 1;

      int minD = INT_MAX;
      for (int k = 1; k <= K; k++) {
        D[i][j][k] = INT_MAX;
        for (int m = i; m < j; m++) {
          D[i][j][k] = min(D[i][j][k], D[i][m][k] + D[m+1][j][k]);
        }
        minD = min(minD, D[i][j][k]);
      }

      for (int k = 1; k <= K; k++) {
        D[i][j][k] = min(D[i][j][k], minD + 1);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  dp();

  int ans = INT_MAX;
  for (int k = 1; k <= K; k++) {
    ans = min(ans, D[1][N][k]);
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
