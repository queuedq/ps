#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9;
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};
int W, H;
string maze[100];
int D[100][100][4];

struct Point {
  int x, y;
  bool oob() { return x < 0 || x >= H || y < 0 || y >= W; }
  Point move(int dir) { return {x+dx[dir], y+dy[dir]}; }
  bool operator ==(const Point &p) const { return pii(x, y) == pii(p.x, p.y); }
};
ostream& operator <<(ostream &os, const Point &p) {
  return os << "{" << p.x << ", " << p.y << "}";
}

vector<Point> cows;
deque<pair<Point, int>> dq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> W >> H;
  for (int i=0; i<H; i++) {
    cin >> maze[i];
    for (int j=0; j<W; j++) {
      if (maze[i][j] == 'C') cows.push_back({i, j});
      fill(D[i][j], D[i][j]+4, INF);
    }
  }

  for (int d=0; d<4; d++) {
    dq.push_back({cows[0], d});
    D[cows[0].x][cows[0].y][d] = 0;
  }

  while (!dq.empty()) {
    auto [pos, dir] = dq.front(); dq.pop_front();

    if (pos == cows[1]) break;

    for (int d=0; d<4; d++) {
      if (dir + d == 3) continue;
      Point nxt = pos.move(d);
      if (nxt.oob() || maze[nxt.x][nxt.y] == '*') continue;

      if (D[pos.x][pos.y][dir] + (d != dir) < D[nxt.x][nxt.y][d]) {
        D[nxt.x][nxt.y][d] = D[pos.x][pos.y][dir] + (d != dir);
        if (d == dir) dq.push_front({nxt, d});
        else dq.push_back({nxt, d});
      }
    }
  }

  int ans = INF;
  for (int d=0; d<4; d++) {
    ans = min(ans, D[cows[1].x][cows[1].y][d]);
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
