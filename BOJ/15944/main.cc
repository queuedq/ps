#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
using piii = pair<int, pii>;
const int MN = 505;
int N, M, D, A[MN][MN], dst[MN][MN];

bool oob(int x, int y) { return x < 1 || x > N || y < 1 || y > M; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> D;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) {
      char c; cin >> c;
      A[i][j] = c == '#';
      dst[i][j] = 1e9;
    }
  }

  deque<pii> dq;
  dst[1][1] = 0;
  dq.push_back({1, 1});
  while (!dq.empty()) {
    auto [x, y] = dq.front(); dq.pop_front();
    int d = dst[x][y];

    for (int i=0; i<4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (!oob(xx, yy) && !A[xx][yy] && d < dst[xx][yy]) {
        dst[xx][yy] = d;
        dq.push_front({xx, yy});
      }

      for (int j=-(D-1); j<=(D-1); j++) {
        int xx = x + dx[i]*D + dy[i]*j;
        int yy = y + dy[i]*D + dx[i]*j;
        xx = min(max(xx, 1), N);
        yy = min(max(yy, 1), M);
        if (d+1 < dst[xx][yy]) {
          dst[xx][yy] = d+1;
          dq.push_back({xx, yy});
        }
      }
    }
  }

  cout << dst[N][M] << endl;

  ////////////////////////////////
  return 0;
}
