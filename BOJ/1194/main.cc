#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

const int MAXN = 55;
int N, M;
string maze[MAXN];
bool vst[MAXN][MAXN][64];

struct Pos {
  int x, y, keys, dist;

  Pos move(int dir) { return {x+dx[dir], y+dy[dir], keys, dist+1}; }
  Pos getKey(int key) { return {x, y, keys | (1<<key), dist}; }

  bool oob() { if (x<0 || x>=N || y<0 || y>=M) return true; return false; }
  bool blocked() {
    if (maze[x][y] == '#') return true;
    if ('A' <= maze[x][y] && maze[x][y] <= 'F') {
      int key = maze[x][y] - 'A';
      if (!(keys & (1<<key))) return true;
    }
    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) cin >> maze[i];

  Pos start = {0, 0, 0, 0};
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      if (maze[i][j] == '0') start = {i, j, 0, 0};
    }
  }

  int ans = -1;
  queue<Pos> Q;
  Q.push(start);
  vst[start.x][start.y][start.keys] = true;
  while (!Q.empty()) {
    Pos p = Q.front(); Q.pop();

    for (int d=0; d<4; d++) {
      Pos q = p.move(d);
      if (q.oob() || q.blocked()) continue;

      char cell = maze[q.x][q.y];
      if (cell == '1') { ans = q.dist; break; }
      if ('a' <= cell && cell <= 'f') q = q.getKey(cell-'a');

      if (vst[q.x][q.y][q.keys]) continue;
      vst[q.x][q.y][q.keys] = true;
      Q.push(q);
    }

    if (ans != -1) break;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
