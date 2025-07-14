#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MX = 505;
int N, M, A[MX][MX];
int P[MX][MX]; // P[i][j]: sum of A[i][1..j]
int up[MX][MX]; // up[l][r]: max rect ending at row i-1, with ends l/r
int down[MX][MX][MX]; // down[i][l][r]: max rect starting at row i, with ends l/r
int rect[MX][MX]; // rect[l][r]: max rect containing row i, with ends l/r
int pmax[MX][MX]; // pmax[l][r]: max rect containing interval [l, r]

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) {
      cin >> A[i][j];
      P[i][j] = P[i][j-1] + A[i][j];
    }
  }

  // precompute down rect
  for (int i=N; i>=1; i--) {
    for (int l=1; l<=M; l++) {
      for (int r=l; r<=M; r++) {
        int sum = P[i][r] - P[i][l-1];
        down[i][l][r] = sum + max(down[i+1][l][r], 0);
      }
    }
  }

  for (int i=1; i<=N; i++) {
    // save max rect
    for (int l=1; l<=M; l++) {
      for (int r=l; r<=M; r++) {
        rect[l][r] = up[l][r] + down[i][l][r];
      }
    }

    // compute pmax
    for (int l=1; l<=M; l++) {
      for (int r=M; r>=l; r--) {
        pmax[l][r] = rect[l][r];
        if (l > 1) pmax[l][r] = max(pmax[l][r], pmax[l-1][r]);
        if (r < M) pmax[l][r] = max(pmax[l][r], pmax[l][r+1]);
      }
    }

    // print ans
    for (int i=1; i<=M; i++) {
      cout << pmax[i][i] << " ";
    }
    cout << endl;

    // compute next up rect
    for (int l=1; l<=M; l++) {
      for (int r=l; r<=M; r++) {
        int sum = P[i][r] - P[i][l-1];
        up[l][r] = max(sum + up[l][r], 0);
      }
    }
  }

  ////////////////////////////////
  return 0;
}
