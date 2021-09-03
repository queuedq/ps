#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505050;
lld N, ans[MN];
pll A[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i].second >> A[i].first;
  sort(A, A+N);
  
  lld sum = 0, mn = LLONG_MAX;
  for (int i=0; i<N; i++) {
    sum += A[i].first;
    mn = min(mn, A[i].second - A[i].first);
    ans[i] = sum + mn;
  }

  mn = LLONG_MAX;
  for (int i=N-1; i>=0; i--) {
    sum -= A[i].first;
    mn = min(mn, A[i].second);
    ans[i] = min(ans[i], sum + mn);
  }

  for (int i=0; i<N; i++) {
    cout << ans[i] << endl;
  }

  ////////////////////////////////
  return 0;
}
