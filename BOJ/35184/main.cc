#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int MX = 505;
const lld INF = 1e18;
lld N, M, T;
char board[MX][MX];
lld dst[MX][MX][4];

bool oob(int x, int y) { return x < 1 || x > N || y < 1 || y > M; }
int rotate(int dir, int dt) { return (dir + dt + 4) % 4; }

struct Node {
  int x, y, dir;
  lld d;
  bool operator<(const Node &X) const { return d < X.d; }
  bool operator>(const Node &X) const { return d > X.d; }
};
Node start;

lld dijkstra() {
  priority_queue<Node, vector<Node>, greater<Node>> pq;
  for (int x=1; x<=N; x++) for (int y=1; y<=M; y++) for (int dir=0; dir<4; dir++) {
    dst[x][y][dir] = INF;
  }
  dst[start.x][start.y][start.dir] = 0;
  pq.push(start);

  while (!pq.empty()) {
    auto [x, y, dir, d] = pq.top(); pq.pop();
    if (d != dst[x][y][dir]) continue;

    // finish
    if (board[x][y] == 'S') return dst[x][y][dir];

    if (board[x][y] == '.') {
      // floor
      int L = rotate(dir, 1);
      int R = rotate(dir, -1);
      int xx = x, yy = y;

      // move left
      xx = x + dx[L], yy = y + dy[L];
      if (!oob(xx, yy) && d + 1 < dst[xx][yy][dir]) {
        dst[xx][yy][dir] = d + 1;
        pq.push({xx, yy, dir, dst[xx][yy][dir]});
      }

      // move right
      xx = x + dx[R], yy = y + dy[R];
      if (!oob(xx, yy) && d + 1 < dst[xx][yy][dir]) {
        dst[xx][yy][dir] = d + 1;
        pq.push({xx, yy, dir, dst[xx][yy][dir]});
      }

      // rotate left
      if (!oob(x, y) && d + T < dst[x][y][L]) {
        dst[x][y][L] = d + T;
        pq.push({x, y, L, dst[x][y][L]});
      }

    } else {
      // tap water
      int L = rotate(dir, 1);
      int xx = x + dx[L], yy = y + dy[L];

      if (!oob(xx, yy) && d < dst[xx][yy][L]) {
        dst[xx][yy][L] = d;
        pq.push({xx, yy, L, dst[xx][yy][L]});
      }
    }
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> T;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) {
      char c; cin >> c;
      board[i][j] = c;
      if ('0' <= c && c <= '3') {
        start = {i, j, c-'0', 0};
        board[i][j] = '.';
      }
    }
  }

  lld d = dijkstra();
  cout << d << endl;

  ////////////////////////////////
  return 0;
}
