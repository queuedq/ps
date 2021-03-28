#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;
lld A[5001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i = 0; i < N; i++) { cin >> A[i]; }
  sort(A, A+N);

  lld best = LLONG_MAX;
  int ans[3];
  for (int k = 0; k < N; k++) {
    for (int i = 0, j = k-1; i < j;) {
      lld s = A[i]+A[j]+A[k];
      if (abs(s) < best) {
        ans[0] = A[i]; ans[1] = A[j]; ans[2] = A[k];
        best = abs(s);
      }
      if (s > 0) { j--; }
      else { i++; }
    }
  }

  cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;

  ////////////////////////////////
  return 0;
}
