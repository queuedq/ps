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
const int ML = 105;
int N, vst[ML][ML][MN][MN];
char maze[MN][MN];
string A, B;

struct Pos { int a, b, x, y; };

bool oob(int x, int y) { return x < 0 || x >= N || y < 0 || y >= N; }

pii get_dir(char c) {
  if (c == 'U') return {-1, 0};
  if (c == 'D') return {1, 0};
  if (c == 'L') return {0, -1};
  if (c == 'R') return {0, 1};
  return {0, 0};
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  queue<Pos> Q;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cin >> maze[i][j];
      if (maze[i][j] == 'S') {
        Q.push({0, 0, i, j});
        vst[0][0][i][j] = 1;
      }
    }
  }
  cin >> A >> B;

  while (!Q.empty()) {
    auto [a, b, x, y] = Q.front(); Q.pop();

    if (a < sz(A)) {
      auto [dx, dy] = get_dir(A[a]);
      int xx = x+dx, yy = y+dy;
      if (oob(xx, yy) || maze[xx][yy] == '#') xx = x, yy = y;
      if (maze[xx][yy] == 'E') return cout << a+b+1 << endl, 0;

      if (!vst[a+1][b][xx][yy]) {
        vst[a+1][b][xx][yy] = 1;
        Q.push({a+1, b, xx, yy});
      }
    }

    if (b < sz(B)) {
      auto [dx, dy] = get_dir(B[b]);
      int xx = x+dx, yy = y+dy;
      if (oob(xx, yy) || maze[xx][yy] == '#') xx = x, yy = y;
      if (maze[xx][yy] == 'E') return cout << a+b+1 << endl, 0;

      if (!vst[a][b+1][xx][yy]) {
        vst[a][b+1][xx][yy] = 1;
        Q.push({a, b+1, xx, yy});
      }
    }
  }

  cout << -1 << endl;

  ////////////////////////////////
  return 0;
}
