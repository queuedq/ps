#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 10'005;
lld N, A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  sort(A, A+N);

  lld ans = 0, side = 0;
  for (int i=N-1; i>0; i--) {
    if (A[i] == A[i-1] || A[i]-1 == A[i-1]) {
      if (side == 0) side = A[i-1];
      else {
        ans += side * A[i-1];
        side = 0;
      }
      i--;
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
