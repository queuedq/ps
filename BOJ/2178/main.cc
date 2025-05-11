#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 105;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int N, M;
char A[MN][MN];
int dst[MN][MN];

bool oob(int x, int y) { return x < 0 || x >= N || y < 0 || y >= M; }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      cin >> A[i][j];
      dst[i][j] = -1;
    }
  }

  queue<pii> Q;
  dst[0][0] = 1;
  Q.push({0, 0});

  while (!Q.empty()) {
    auto [x, y] = Q.front(); Q.pop();

    for (int d=0; d<4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];

      // unreachable
      if (oob(nx, ny) || A[nx][ny] == '0') continue;
      // already visited
      if (dst[nx][ny] != -1) continue;

      dst[nx][ny] = dst[x][y] + 1;
      Q.push({nx, ny});
    }
  }

  cout << dst[N-1][M-1] << endl;

  ////////////////////////////////
  return 0;
}
