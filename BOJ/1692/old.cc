#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 55;
const int MAXP = 1<<16;
const int INF = MAXN * 16;
int N;
bool A[MAXN][16];
int D[2][16][MAXP];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    string s; cin >> s;
    for (int j=0; j<16; j++) A[i][j] = s[j]-'0';
  }

  for (int j=0; j<16; j++) {
    for (int k=1; k<1<<16; k++) {
      D[0][j][k] = INF;
    }
  }

  for (int i=0; i<N; i++) {
    for (int j=0; j<16; j++) {
      for (int k=0; k<1<<16; k++) {
        int v = !!(k & 1<<j); // vertical cover
        int h = v ^ A[i][j]; // horizontal cover

        if (j == 0) {
          D[1][j][k] = min(D[0][15][k], D[0][15][k ^ 1<<j] + v) + h;
        } else {
          int vv = !!(k & 1<<(j-1));
          int hh = vv ^ A[i][j-1];
          D[1][j][k] = min(D[1][j-1][k], D[1][j-1][k ^ 1<<j] + v) + (!hh && h);
        }
      }
    }

    for (int j=0; j<16; j++) {
      for (int k=0; k<1<<16; k++) D[0][j][k] = D[1][j][k];
    }
  }

  int ans = INT_MAX;
  for (int k=0; k<1<<16; k++) {
    ans = min(ans, D[0][15][k]);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
