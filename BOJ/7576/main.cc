#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9;
const int MN = 1005;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int N, M, A[MN][MN], dst[MN][MN];

bool oob(int x, int y) { return x < 0 || x >= N || y < 0 || y >= M; }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> M >> N;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      cin >> A[i][j];
      dst[i][j] = INF;
    }
  }

  // init queue
  queue<pii> Q;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      if (A[i][j] == 1) { // ripe tomato
        dst[i][j] = 0;
        Q.push({i, j});
      }
    }
  }

  // BFS
  while (!Q.empty()) {
    auto [x, y] = Q.front(); Q.pop();

    for (int d=0; d<4; d++) {
      int nx = x + dx[d], ny = y + dy[d];

      if (oob(nx, ny) || A[nx][ny] == -1) continue; // unreachable
      if (dst[nx][ny] != INF) continue; // already visited

      dst[nx][ny] = dst[x][y] + 1;
      Q.push({nx, ny});
    }
  }

  // check ans
  int ans = 0;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      if (A[i][j] != -1) ans = max(ans, dst[i][j]);
    }
  }

  if (ans == INF) ans = -1;
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
