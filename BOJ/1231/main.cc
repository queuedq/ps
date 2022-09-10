#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505050;
int C, D, M;
int w[11][51], dp[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> C >> D >> M;
  for (int j=1; j<=C; j++) {
    for (int i=1; i<=D; i++) cin >> w[i][j];
  }

  for (int i=1; i<D; i++) {
    fill(dp, dp+M+1, 0);
    for (int j=1; j<=C; j++) {
      for (int x=w[i][j]; x<=M; x++) {
        dp[x] = max(dp[x], dp[x-w[i][j]] + w[i+1][j] - w[i][j]);
      }
    }
    M += dp[M];
  }

  cout << M << endl;

  ////////////////////////////////
  return 0;
}
