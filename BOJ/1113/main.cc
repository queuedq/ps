#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int MN = 55;
int N, M, A[MN][MN], vst[MN][MN], ans;

bool oob(int x, int y) {
  return x < 0 || x > N+1 || y < 0 || y > M+1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) {
    string S; cin >> S;
    for (int j=1; j<=M; j++) A[i][j] = S[j-1] - '0';
  }

  for (int h=2; h<=9; h++) {
    for (int x=0; x<=N+1; x++) {
      for (int y=0; y<=M+1; y++) vst[x][y] = 0;
    }

    queue<pii> Q;
    Q.push({0, 0});
    vst[0][0] = 1;

    while (!Q.empty()) {
      auto [x, y] = Q.front(); Q.pop();
      for (int d=0; d<4; d++) {
        int nx = x+dx[d], ny = y+dy[d];
        if (oob(nx, ny) || A[nx][ny] >= h || vst[nx][ny]) continue;
        Q.push({nx, ny});
        vst[nx][ny] = 1;
      }
    }

    for (int x=1; x<=N; x++) {
      for (int y=1; y<=M; y++) {
        if (A[x][y] < h && !vst[x][y]) ans++;
      }
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
