#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 1e9;
const int MAXN = 1005;
lld N, M, d[MAXN], w[MAXN], s[MAXN], D[MAXN][MAXN][2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) {
    cin >> d[i] >> w[i];
    s[i] = s[i-1] + w[i];
  }

  for (int i=0; i<=N+1; i++) for (int j=0; j<=N+1; j++) {
    D[i][j][0] = D[i][j][1] = INF;
  }
  D[1][N][0] = D[1][N][1] = 0;

  for (int l=N-1; l>=1; l--) {
    for (int i=1, j=i+l-1; j<=N; i++, j++) {
      lld on = s[N] - s[j] + s[i-1];

      D[i][j][0] = min(
        D[i-1][j][0] + (d[i] - d[i-1]) * on,
        D[i][j+1][1] + (d[j+1] - d[i]) * on
      );
      D[i][j][1] = min(
        D[i][j+1][1] + (d[j+1] - d[j]) * on,
        D[i-1][j][0] + (d[j] - d[i-1]) * on
      );
    }
  }

  cout << D[M][M][0] << endl;

  ////////////////////////////////
  return 0;
}
