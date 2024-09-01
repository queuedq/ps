#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int _N = 3005;
const int _M = 105;
int N, M, A[_N], B[_N];
// D[i][j][k][p]: A[1..i], B[1..j], pick k Bs, pick current
int D[_N][_M][_M][2];

void set_max(int &x, int y) { x = max(x, y); }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  cin >> M;
  for (int i=1; i<=M; i++) cin >> B[i];
  sort(B+1, B+M+1);
  reverse(B+1, B+M+1);

  for (int i=0; i<=N; i++) {
    for (int j=0; j<=M; j++) {
      for (int k=0; k<=j; k++) {
        // no pick
        if (i > 0) set_max(D[i][j][k][0], max(D[i-1][j][k][0], D[i-1][j][k][1])); // current A
        if (j > 0) set_max(D[i][j][k][0], max(D[i][j-1][k][0], D[i][j-1][k][1])); // current B

        // pick
        if (i > 0) set_max(D[i][j][k][1], D[i-1][j][k][0] + A[i]); // current A
        if (j > 0 && k > 0) set_max(D[i][j][k][1], D[i][j-1][k-1][0] + B[k]); // current B
      }
    }
  }

  int ans = 0;
  for (int k=0; k<=M; k++) set_max(ans, max(D[N][M][k][0], D[N][M][k][1]));
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
