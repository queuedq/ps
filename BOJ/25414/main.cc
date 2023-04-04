#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
const int MR = 202;
const lld INF = 1e18;
int N, R;
lld A[MN], D[2][MR], E[2][MR][2];
// D[i][j]: from A[1..i], j intervals
// E[i][j][k]: with incomplete interval

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> R;
  for (int i=1; i<=N; i++) cin >> A[i];

  for (int i: {0, 1}) {
    for (int j=0; j<=R; j++) D[i][j] = E[i][j][0] = E[i][j][1] = -INF;
    D[i][0] = 0;
  }

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=R; j++) {
      E[i&1][j][0] = max({E[~i&1][j][0], D[~i&1][j-1] - A[i]});
      E[i&1][j][1] = max({E[~i&1][j][1], D[~i&1][j-1] + A[i]});
      D[i&1][j] = max({D[~i&1][j], E[i&1][j][0] + A[i], E[i&1][j][1] - A[i]});
    }
  }

  for (int j=1; j<=R; j+=1) cout << D[N&1][j] << endl;

  ////////////////////////////////
  return 0;
}
