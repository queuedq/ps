#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1505;
int N, A[MN][MN], D[MN][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) cin >> A[i][j];
  }

  D[2][1] = A[2][1];
  for (int i=3; i<=N; i++) {
    D[i][i-1] = INT_MAX;
    for (int j=1; j<=i-2; j++) {
      D[i][j] = D[i-1][j] + A[i][i-1];
      D[i][i-1] = min(D[i][i-1], D[i-1][j] + A[i][j]);
    }
  }

  int ans = INT_MAX;
  for (int i=1; i<=N-1; i++) ans = min(ans, D[N][i]);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
