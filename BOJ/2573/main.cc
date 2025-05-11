#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MN = 305;
int N, M, A[MN][MN], vst[MN][MN];
int tmp[MN][MN];

bool oob(int x, int y) { return x < 0 || x >= N || y < 0 || y >= M; }

void bfs(int sx, int sy) {
  queue<pii> Q;
  vst[sx][sy] = 1;
  Q.push({sx, sy});

  while (!Q.empty()) {
    auto [x, y] = Q.front(); Q.pop();

    for (int d=0; d<4; d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if (oob(nx, ny) || A[nx][ny] == 0) continue;
      if (vst[nx][ny]) continue;

      vst[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }
}

int icebergs() { // count components
  for (int i=0; i<N; i++) {
    fill(vst[i], vst[i]+M, 0);
  }

  int cnt = 0;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      if (oob(i, j) || A[i][j] == 0) continue;
      if (vst[i][j]) continue;

      bfs(i, j);
      cnt++;
    }
  }

  return cnt;
}

void melt() {
  for (int x=0; x<N; x++) {
    for (int y=0; y<M; y++) {
      tmp[x][y] = A[x][y];

      // melt by number of adjacent water cells
      for (int d=0; d<4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (!oob(nx, ny) && A[nx][ny] == 0) tmp[x][y]--;
      }
      tmp[x][y] = max(tmp[x][y], 0);
    }
  }

  for (int x=0; x<N; x++) {
    for (int y=0; y<M; y++) {
      A[x][y] = tmp[x][y];
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
    }
  }

  int ans = 0;

  // find first time with 2+ components
  for (int t=0;; t++) {
    int cnt = icebergs();
    if (cnt >= 2) { ans = t; break; }
    if (cnt == 0) { ans = 0; break; }

    melt();
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
