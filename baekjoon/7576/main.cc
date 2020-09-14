#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};
int N, M, dst[MAXN][MAXN];
bool A[MAXN][MAXN];

bool oob(int x, int y) { return x<0 || x>=N || y<0 || y>=M; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> M >> N;
  queue<pii> q;

  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      dst[i][j] = -1;

      int a; cin >> a;
      A[i][j] = a != -1;
      if (a == 1) {
        q.push({i, j});
        dst[i][j] = 0;
      }
    }
  }

  int ans = 0;
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();

    for (int d=0; d<4; d++) {
      int vx = x+dx[d], vy = y+dy[d];
      if (oob(vx, vy) || !A[vx][vy] || dst[vx][vy] != -1) continue;
      q.push({vx, vy});
      ans = dst[vx][vy] = dst[x][y]+1;
    }
  }

  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (A[i][j] && dst[i][j] == -1) ans = -1;
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
