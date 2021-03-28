#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int MN = 1005;
int m, n, A[MN][MN], vst[MN][MN], dst[MN][MN];

bool oob(int x, int y) { return x<0 || x>=m || y<0 || y>=n; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> m >> n;
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) cin >> A[i][j];
  }

  priority_queue<pair<int, pii>> pq;
  if (A[0][0] != -1) pq.push({-A[0][0], {0, 0}});

  while (!pq.empty()) {
    auto [w, p] = pq.top(); pq.pop();
    auto [x, y] = p;
    if (vst[x][y]) continue;
    vst[x][y] = true;
    dst[x][y] = -w;

    for (int d: {0, 1, 2, 3}) {
      int xx = x+dx[d], yy = y+dy[d];
      if (oob(xx, yy) || A[xx][yy] == -1) continue;
      pq.push({w - A[xx][yy], {xx, yy}});
    }
  }

  if (!vst[m-1][n-1]) cout << -1 << endl;
  else cout << dst[m-1][n-1] << endl;

  ////////////////////////////////
  return 0;
}
