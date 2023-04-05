#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, A[105];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    cin >> N;
    for (int i=0; i<N; i++) cin >> A[i];

    int ans = 0;
    for (int i=0; i<N-1; i++) {
      int j = min_element(A+i, A+N) - A;
      reverse(A+i, A+j+1);
      ans += j-i+1;
    }
    printf("Case #%d: %d\n", t, ans);
  }

  ////////////////////////////////
  return 0;
}
