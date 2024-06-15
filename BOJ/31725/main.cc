#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2020;
int N, K, A[MN][MN], D[MN][MN], E[MN][MN], L[MN][MN], R[MN][MN];
// L[i][j]: max cost moving down from row i col [1..j]
// R[i][j]: max cost moving down from row i col [j..N]

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) cin >> A[i][j];

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) D[i][j] = A[i][j] + max(D[i][j-1], D[i-1][j]);
  }
  for (int i=N; i>=1; i--) {
    for (int j=N; j>=1; j--) E[i][j] = A[i][j] + max(E[i][j+1], E[i+1][j]);
  }

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) L[i][j] = max(L[i][j-1], D[i][j] + E[i+1][j]);
    for (int j=N; j>=1; j--) R[i][j] = max(R[i][j+1], D[i][j] + E[i+1][j]);
  }

  int ans = INT_MAX;
  for (int i=1; i<=N-K+1; i++) {
    for (int j=1; j<=N-K+1; j++) {
      if ((i==1 && j==1) || (i==N-K+1 && j==N-K+1)) continue;
      int cost = 0;
      if (i<=N-K && j>1) cost = max(cost, L[i+K-1][j-1]);
      if (i>1 && j<=N-K) cost = max(cost, R[i-1][j+K]);
      ans = min(ans, cost);
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
