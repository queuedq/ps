#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int H = 5, W = 9;
const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};
char board[5][9];

bool oob(int i, int j) { return i<0 || i>=H || j<0 || j>=W; }

int solve() {
  int ret = 0;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      if (board[i][j] != 'o') continue;

      for (int d=0; d<4; d++) {
        if (oob(i+dx[d]*2, j+dy[d]*2)) continue;
        if (board[i+dx[d]][j+dy[d]] != 'o') continue;
        if (board[i+dx[d]*2][j+dy[d]*2] != '.') continue;

        board[i][j] = '.';
        board[i+dx[d]][j+dy[d]] = '.';
        board[i+dx[d]*2][j+dy[d]*2] = 'o';

        ret = max(ret, solve()+1);

        board[i][j] = 'o';
        board[i+dx[d]][j+dy[d]] = 'o';
        board[i+dx[d]*2][j+dy[d]*2] = '.';
      }
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int N; cin >> N;

  for (int t=0; t<N; t++) {
    int cnt = 0;

    for (int i=0; i<H; i++) {
      for (int j=0; j<W; j++) {
        cin >> board[i][j];
        if (board[i][j] == 'o') cnt++;
      }
    }

    int move = solve();
    cout << cnt - move << " " << move << endl;
  }

  ////////////////////////////////
  return 0;
}
