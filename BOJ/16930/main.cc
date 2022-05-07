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
const int MN = 1010;
int N, M, K, A[MN][MN], dst[MN][MN];

bool oob(int x, int y) { return x < 1 || x > N || y < 1 || y > M; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) {
      char c; cin >> c;
      A[i][j] = c == '#';
      dst[i][j] = 1e9;
    }
  }

  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

  queue<pair<int, pii>> Q;
  dst[x1][y1] = 0;
  Q.push({0, {x1, y1}});
  while (!Q.empty()) {
    auto [d, pos] = Q.front(); Q.pop();
    auto [x, y] = pos;
    for (int i=0; i<4; i++) {
      for (int j=1; j<=K; j++) {
        int xx = x+dx[i]*j, yy = y+dy[i]*j;
        if (oob(xx, yy) || A[xx][yy] || dst[xx][yy] < d+1) break;
        if (dst[xx][yy] > d+1) {
          dst[xx][yy] = d+1;
          Q.push({d+1, {xx, yy}});
        }
      }
    }
  }

  if (dst[x2][y2] == 1e9) cout << -1 << endl;
  else cout << dst[x2][y2] << endl;

  ////////////////////////////////
  return 0;
}
