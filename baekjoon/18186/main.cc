#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e6+5;
lld N, B, C, A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> B >> C;
  for (int i=1; i<=N; i++) cin >> A[i];

  if (B <= C) {
    lld sum = 0;
    for (int i=1; i<=N; i++) sum += A[i];
    cout << sum * B << endl;
    return 0;
  }

  lld ans = 0;
  for (int i=N; i>=1; i--) {
    // Invariant: A[i] >= A[i+1] >= A[i+2]
    ans += A[i+2] * (B+C+C);
    A[i] -= A[i+2];
    A[i+1] -= A[i+2];
    A[i+2] = 0;
    if (A[i-1] < A[i]) {
      lld r = min(A[i] - A[i-1], A[i+1]);
      ans += r * (B+C);
      A[i] -= r;
      A[i+1] -= r;
    }
    if (A[i-1] < A[i]) {
      assert(A[i+1] == 0);
      ans += (A[i] - A[i-1]) * B;
      A[i] = A[i-1];
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
