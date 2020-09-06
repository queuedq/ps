#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 2e5+5;
lld N, A[MAXN], B[MAXN];

void solve(int test) {
  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  for (int i=0; i<N; i++) cin >> B[i];

  sort(A, A+N);
  sort(B, B+N);

  lld p = 0, mxp = 0, ans = -abs(A[0]-B[0]);
  for (int i=0; i<N-1; i++) {
    p += abs(A[i+1]-B[i]) - abs(A[i]-B[i]);
    mxp = max(mxp, p);
    ans = min(ans, p-mxp - abs(A[i+1]-B[i+1]));
  }

  p = 0, mxp = 0;
  for (int i=0; i<N-1; i++) {
    p += abs(A[i]-B[i+1]) - abs(A[i]-B[i]);
    mxp = max(mxp, p);
    ans = min(ans, p-mxp - abs(A[i+1]-B[i+1]));
  }

  for (int i=0; i<N; i++) {
    ans += abs(A[i]-B[i]);
  }

  cout << "Case #" << test << endl;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
