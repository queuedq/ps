#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAX_H = 55;
int H1, W1, H2, W2;
int rect[MAX_H][MAX_H], L[MAX_H][MAX_H][MAX_H][MAX_H];

void dp1() {
  for (int i = 1; i <= H1; i++) {
    for (int j = 1; j <= W1; j++) {
      if (i == 1 || j == 1) { rect[i][j] = max(i, j); continue; }
      if (i == j) { rect[i][j] = 1; continue; }

      rect[i][j] = INT_MAX;
      for (int k = 1; k <= i / 2; k++) {
        rect[i][j] = min(rect[i][j], rect[k][j] + rect[i-k][j]);
      }
      for (int k = 1; k <= j / 2; k++) {
        rect[i][j] = min(rect[i][j], rect[i][k] + rect[i][j-k]);
      }
    }
  }
  // for (int i = 1; i <= H1; i++) {
  //   for (int j = 1; j <= W1; j++) {
  //     cout << i << j << rect[i][j] << endl;
  //   }
  // }
}

void dp2() {
  for (int i = 1; i <= H1; i++) {
    for (int j = 1; j <= W1; j++) {
      for (int k = 1; k < i; k++) {
        for (int l = 1; l < j; l++) {
          L[i][j][k][l] = min(rect[i-k][j] + rect[k][j-l], rect[i][j-l] + rect[i-k][l]);

          for (int m = 1; m < i-k; m++) {
            L[i][j][k][l] = min(L[i][j][k][l], rect[m][j] + L[i-m][j][k][l]);
          }
          for (int m = i-k+1; m < i; m++) {
            L[i][j][k][l] = min(L[i][j][k][l], L[m][j][k-i+m][l] + rect[i-m][j-l]);
          }

          for (int m = 1; m < j-l; m++) {
            L[i][j][k][l] = min(L[i][j][k][l], rect[i][m] + L[i][j-m][k][l]);
          }
          for (int m = j-l+1; m < j; m++) {
            L[i][j][k][l] = min(L[i][j][k][l], L[i][m][k][l-j+m] + rect[i-k][j-m]);
          }
          // cout << i << j << k << l << L[i][j][k][l] << endl;
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> H1 >> W1 >> H2 >> W2;
  dp1();
  dp2();
  cout << L[H1][W1][H2][W2] << endl;

  ////////////////////////////////
  return 0;
}
