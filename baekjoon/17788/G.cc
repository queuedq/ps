#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int r, c, k;
int grid[100][100];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  for (int i=0; i<100; i++) fill(grid[i], grid[i]+100, -1);

  cin >> r >> c >> k;
  queue<pii> q;

  for (int i=0; i<r; i++) {
    string s; cin >> s;
    for (int j=0; j<c; j++) {
      if (s[j] == '#') {
        grid[i+40][j+40] = 0;
        q.push({i+40, j+40});
      }
    }
  }

  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    if (grid[x][y] >= min(k, 20)) break;

    for (int d=0; d<8; d++) {
      if (grid[x+dx[d]][y+dy[d]] == -1) {
        grid[x+dx[d]][y+dy[d]] = grid[x][y] + 1;
        q.push({x+dx[d], y+dy[d]});
      }
    }
  }

  lld ans = 0;
  int xl = 100, xr = -1, yl = 100, yr = -1;
  for (int i=0; i<100; i++) {
    for (int j=0; j<100; j++) {
      if (grid[i][j] != -1) {
        ans++;
        xl = min(xl, i);
        xr = max(xr, i);
        yl = min(yl, j);
        yr = max(yr, j);
      }
    }
  }

  if (ans == 0) {
    cout << 0 << endl;
    return 0;
  }
  if (k <= 20) {
    cout << ans << endl;
    return 0;
  }

  lld base = (xr-xl+1 + yr-yl+1) * 2 + 4;
  cout << ans + (base + base+8*(k-20-1)) * (k-20) / 2 << endl;

  ////////////////////////////////
  return 0;
}
