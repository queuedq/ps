#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};
const int MN = 1030;
int H, W, r, c, d, A[MN][MN], B[MN][MN];
int clean[MN][MN], vst[MN][MN][4];
int last = 0;

bool oob(int r, int c) {
  return r < 0 || r >= H || c < 0 || c >= W;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> H >> W >> r >> c >> d;
  for (int i=0; i<H; i++) {
    string S; cin >> S;
    for (int j=0; j<W; j++) A[i][j] = S[j] - '0';
  }
  for (int i=0; i<H; i++) {
    string S; cin >> S;
    for (int j=0; j<W; j++) B[i][j] = S[j] - '0';
  }

  for (int t=1;; t++) {
    if (!clean[r][c]) {
      last = clean[r][c] = t;
      d = (d + A[r][c]) % 4;
    } else {
      d = (d + B[r][c]) % 4;
    }
    r += dr[d], c += dc[d];

    if (oob(r, c) || vst[r][c][d] > last) break;
    vst[r][c][d] = t;
  }

  cout << last << endl;

  ////////////////////////////////
  return 0;
}
