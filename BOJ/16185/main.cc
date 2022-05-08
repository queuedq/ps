#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 250'005;
const int MK = 10;
const lld INF = 1e18;
lld N, K, W[MN], D[MN][MK][MK][3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) cin >> W[i];

  for (int j=0; j<=K; j++)
    for (int k=0; k<=K; k++)
      for (int l=0; l<3; l++)
        D[0][j][k][l] = INF;
  D[0][0][0][1] = 0;

  for (int i=1; i<=N; i++) { // current pos
    for (int j=0; j<=K; j++) { // excluding lights
      for (int k=0; k<=K; k++) { // including lights
        D[i][j][k][0] = INF;
        for (int l: {0, 1, 2}) { // dist to last light
          D[i][j][k][0] = min(D[i][j][k][0], D[i-1][j][k][l] + W[i]);
          if (j > 0) D[i][j][k][0] = min(D[i][j][k][0], D[i-1][j-1][k][l]);
        }

        for (int l: {1, 2}) {
          D[i][j][k][l] = D[i-1][j][k][l-1];
          if (k > 0) D[i][j][k][l] = min(D[i][j][k][l], D[i-1][j][k-1][l-1] + W[i]);
        }
      }
    }
  }

  lld ans = INF;
  for (int j=0; j<=K; j++)
    for (int k=j; k<=K; k++)
      for (int l: {0, 1})
        ans = min(ans, D[N][j][k][l]);

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
