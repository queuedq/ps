#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 505;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int M, N, H[MAXN][MAXN], D[MAXN][MAXN];

struct Pos {
  int x, y, h;
  bool operator <(Pos p) const { return h > p.h; }
};
vector<Pos> P;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> M >> N;
  for (int i=1; i<=M; i++) {
    for (int j=1; j<=N; j++) {
      cin >> H[i][j];
      P.push_back({i, j, H[i][j]});
    }
  }

  sort(P.begin(), P.end());
  D[1][1] = 1;

  for (int i=0; i<M*N; i++) {
    auto [x, y, h] = P[i];
    for (int d=0; d<4; d++) {
      if (H[x][y] < H[x+dx[d]][y+dy[d]]) {
        D[x][y] += D[x+dx[d]][y+dy[d]];
      }
    }
  }

  cout << D[M][N] << endl;

  ////////////////////////////////
  return 0;
}
