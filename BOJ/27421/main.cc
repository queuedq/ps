#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101;
const int MR = 10101;
int N, R[MN], tot, dp[2][MN*MR][2];
// dp[i][s][b]: number of ways to make sum s, with b (parity) positive terms

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  // - partition into sets A, B with same R[i] sum
  // - both |A|, |B| must be even
  // - 2 different partitions needed for each x, y axis
  // - one partition contributes to dp by 2, so at least 4 number of ways needed

  cin >> N;
  for (int i=1; i<=N; i++) cin >> R[i];

  dp[0][0][0] = 1;
  for (int i=1; i<=N; i++) {
    tot += R[i];
    auto D = dp[i&1], E = dp[~i&1];

    for (int s=0; s<=tot; s++) {
      D[s][0] = E[s][0];
      D[s][1] = E[s][1];
      if (s >= R[i]) {
        D[s][0] += E[s-R[i]][1];
        D[s][1] += E[s-R[i]][0];
      }
      D[s][0] = min(D[s][0], 4);
      D[s][1] = min(D[s][1], 4);
    }
  }

  if (N%2 == 1 || tot%2 == 1) { cout << "No" << endl; return 0; }
  if (dp[N&1][tot/2][0] >= 4) cout << "Yes" << endl;
  else cout << "No" << endl;

  ////////////////////////////////
  return 0;
}
