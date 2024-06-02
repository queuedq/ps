#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 25;
const int dx[9] = {0, 1, 1, 0, -1, -1, -1, 0, 1};
const int dy[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
int N, M, board[MN][MN], dst[MN][MN][MN][MN];

struct Point {
  int x, y;
  bool operator==(const Point &P) const { return x == P.x && y == P.y; }
  Point move(int dir) { return {x+dx[dir], y+dy[dir]}; }
  bool is_wall() { return x < 0 || x >= N || y < 0 || y >= M || board[x][y]; }
};
Point SA, SB;

struct Node { Point A, B; int d; };

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      char c; cin >> c;
      if (c == 'X') board[i][j] = 1;
      if (c == 'A') SA = {i, j};
      if (c == 'B') SB = {i, j};
    }
  }

  memset(dst, -1, sizeof(dst));
  queue<Node> Q;
  Q.push({SA, SB, dst[SA.x][SA.y][SB.x][SB.y] = 0});

  while (!Q.empty()) {
    auto [A, B, d] = Q.front(); Q.pop();
    
    for (int da=0; da<9; da++) {
      for (int db=0; db<9; db++) {
        Point A1 = A.move(da);
        Point B1 = B.move(db);
        if (A1.is_wall() || B1.is_wall()) continue;
        if (A1 == B1) continue; // same place not allowed
        if (A1 == B && B1 == A) continue; // swap not allowed
        
        if (dst[A1.x][A1.y][B1.x][B1.y] == -1) {
          dst[A1.x][A1.y][B1.x][B1.y] = d+1;
          Q.push({A1, B1, d+1});
        }
      }
    }
  }

  cout << dst[SB.x][SB.y][SA.x][SA.y] << endl;

  ////////////////////////////////
  return 0;
}
