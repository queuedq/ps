#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MH = 1010;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int H, W, A[MH][MH];

bool oob(int x, int y) {
  return x <= 0 || x > H || y <= 0 || y > W;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> H >> W;
  for (int i=1; i<=H; i++) {
    for (int j=1; j<=W; j++) cin >> A[i][j];
  }

  int ans = 0;
  for (int i=1; i<=H; i++) {
    for (int j=1; j<=W; j++) {
      if (A[i][j] == -1 || A[i][j] == 0) continue;

      bool light = 1, ok = 1;
      for (int d=0; d<4; d++) {
        int ii = i+dx[d], jj = j+dy[d];
        if (oob(ii, jj) || A[ii][jj] == -1) continue;
        if (A[i][j] < A[ii][jj]) light = 0;
        if (A[i][j] - A[ii][jj] >= 2) ok = 0;
      }

      if (!ok) { cout << -1 << endl; return 0; }
      ans += light;
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
