#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1e9;
const int MN = 1005;
int N, M, dst[MN][MN][2];
char A[MN][MN];

bool oob(int x, int y) { return x < 0 || x >= N || y < 0 || y >= M; }

struct State {
  int x, y, b; // b: has broken wall?
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      cin >> A[i][j];
      dst[i][j][0] = dst[i][j][1] = INF;
    }
  }

  // BFS
  queue<State> Q;
  Q.push({0, 0, 0});
  dst[0][0][0] = 1;

  while (!Q.empty()) {
    auto [x, y, b] = Q.front(); Q.pop();

    for (int d=0; d<4; d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if (oob(nx, ny)) continue;

      if (b && A[nx][ny] == '1') continue; // cannot break wall again
      int nb = b || A[nx][ny] == '1';

      if (dst[nx][ny][nb] != INF) continue;
      dst[nx][ny][nb] = dst[x][y][b] + 1;
      Q.push({nx, ny, nb});
    }
  }

  // print ans
  int ans = min(dst[N-1][M-1][0], dst[N-1][M-1][1]);
  if (ans == INF) ans = -1;
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
