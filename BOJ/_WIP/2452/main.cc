#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int M, N, A[105][105], dst[105][105];

bool oob(int x, int y) { return x < 0 || x >= M || y < 0 || y >= N; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> M >> N;
  for (int i=0; i<M; i++) for (int j=0; j<N; j++) cin >> A[i][j];

  int ans = INT_MAX;
  for (int i=0; i<M; i++) {
    for (int j=0; j<N; j++) {
      // reset
      for (int k=0; k<M; k++) fill(dst[k], dst[k]+N, -1);

      // center first
      int ii = (i+M/2) % M, jj = (j+N/2) % N;

      // 0-1 bfs
      deque<pii> dq;
      dq.push_back({ii, jj});
      dst[ii][jj] = 0;
      int maxd = 0;

      while (!dq.empty()) {
        auto [x, y] = dq.front(); dq.pop_front();
        maxd = dst[x][y];
        if (maxd >= ans) break;

        for (int t=0; t<4; t++) {
          int xx = x+dx[t], yy = y+dy[t];
          if (oob(xx, yy) || dst[xx][yy] >= 0) continue;
          if (A[x][y] == A[xx][yy]) {
            dq.push_front({xx, yy});
            dst[xx][yy] = dst[x][y];
          } else {
            dq.push_back({xx, yy});
            dst[xx][yy] = dst[x][y]+1;
          }
        }
      }

      ans = min(ans, maxd);
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
