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
const int MN = 35;
const int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int N, M, A[MN][MN], sx, sy, ex, ey;
int dst[MN][MN], vst[MN][MN];
lld cnt[MN][MN];
queue<array<int, 3>> Q;

bool oob(int x, int y) { return x < 0 || x >= N || y < 0 || y >= M; }

void dfs_next(int x, int y, int d, lld c) {
  for (int i=0; i<8; i++) {
    int xx = x+dx[i], yy = y+dy[i];
    if (oob(xx, yy) || A[xx][yy] == 2 || vst[xx][yy]) continue;
    vst[xx][yy] = 1;

    if (A[xx][yy] == 1) {
      dfs_next(xx, yy, d, c);
    } else {
      if (d+1 <= dst[xx][yy]) cnt[xx][yy] += c;
      if (dst[xx][yy] <= d+1) continue;
      dst[xx][yy] = d+1;
      Q.push({xx, yy, d+1});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      cin >> A[i][j];
      if (A[i][j] == 3) sx = i, sy = j, A[i][j] = 1;
      if (A[i][j] == 4) ex = i, ey = j, A[i][j] = 0;
    }
  }

  // bfs
  for (int i=0; i<N; i++) fill(dst[i], dst[i]+M, INF);
  Q.push({sx, sy, dst[sx][sy] = 0});
  cnt[sx][sy] = 1;

  while (!Q.empty()) {
    auto [x, y, d] = Q.front(); Q.pop();
    for (int i=0; i<N; i++) fill(vst[i], vst[i]+M, 0);
    vst[x][y] = 1;
    dfs_next(x, y, d, cnt[x][y]);
  }

  if (dst[ex][ey] == INF) cout << -1 << endl;
  else {
    cout << dst[ex][ey] - 1 << endl;
    cout << cnt[ex][ey] << endl;
  }

  ////////////////////////////////
  return 0;
}
