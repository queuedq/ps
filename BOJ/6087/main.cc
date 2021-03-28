#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};
int W, H;
int D[100][100];
string maze[100];

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> W >> H;
  for (int i=0; i<H; i++) {
    cin >> maze[i];
    for (int j=0; j<W; j++) {
      if (maze[i][j] == 'C') cows.push_back({i, j});
    }
    fill(D[i], D[i]+W, -1);
  }

  queue<Point> q;
  q.push(cows[0]);
  D[cows[0].x][cows[0].y] = 0;

  int ans = 0;
  while (!q.empty()) {
    Point pos = q.front(); q.pop();
    if (pos == cows[1]) { ans = D[pos.x][pos.y]-1; break; }

    for (int d=0; d<4; d++) {
      Point cur = pos.move(d);
      while (true) {
        if (cur.oob() || maze[cur.x][cur.y] == '*') break;
        if (D[cur.x][cur.y] == -1) {
          D[cur.x][cur.y] = D[pos.x][pos.y] + 1;
          q.push(cur);
        }
        cur = cur.move(d);
      }
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
