#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
 
////////////////////////////////////////////////////////////////
const int MN = 1010;
int H, W, sx, sy, ex, ey;
char board[MN][MN];
string wind;
 
bool oob(int x, int y) { return x < 1 || x > H || y < 1 || y > W; }
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////
 
  cin >> H >> W >> sx >> sy >> ex >> ey;
  for (int i=1; i<=H; i++) {
    for (int j=1; j<=W; j++) cin >> board[i][j];
  }
  cin >> wind;
  int T = sz(wind);
 
  // simulate
  bool ok = true;
  int x = ex, y = ey;
  string ans(T, '.');
 
  for (int i=T-1; i>=0; i--) {
    char w = wind[i];
    // reversed direction
    int dx = 0, dy = 0;
    if (w == 'U') dx = 1;
    else if (w == 'R') dy = -1;
    else if (w == 'D') dx = -1;
    else if (w == 'L') dy = 1;
 
    // move if possible
    int nx = x + dx, ny = y + dy;
    if (oob(nx, ny)) {
      ok = false;
      break;
    } else if (board[nx][ny] == '.') {
      x = nx, y = ny;
      ans[i] = 'F';
    } else {
      ans[i] = 'G';
    }
  }
 
  // print ans
  if (ok && x == sx && y == sy) {
    cout << "YES" << endl;
    cout << ans << endl;
  } else {
    cout << "NO" << endl;
  }
 
  ////////////////////////////////
  return 0;
}
