#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
lld N, A[MN][MN], S[MN][MN], D[MN][MN], E[MN][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  while (1) {
    cin >> N;
    if (N == 0) break;
    for (int i=1; i<=N; i++) {
      for (int j=1; j<=i; j++) {
        cin >> A[i][j];
        S[i][j] = S[i-1][j] + A[i][j];
      }
    }

    for (int j=1; j<=N; j++) {
      D[N+1][j] = LLONG_MIN;
      for (int i=N; i>=j-1; i--) {
        D[i][j] = max(D[i+1][j], D[i-1][j-1] + S[i][j]);
      }
    }

    cout << D[N-1][N] << endl;
  }

  ////////////////////////////////
  return 0;
}
