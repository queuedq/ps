#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1005;
int N, A[MN][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    cin >> N;
    
    int ans = 0;
    for (int i=1; i<=N; i++) {
      for (int j=i+1; j<=N; j++) {
        cin >> A[i][j];
        A[j][i] = A[i][j];
      }

      int red = 0;
      for (int j=1; j<=N; j++) red += A[i][j];
      ans += red * (N-1-red);
    }

    ans = N*(N-1)*(N-2)/6 - ans/2;
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
