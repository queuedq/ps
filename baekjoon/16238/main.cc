#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1005;
int N, A[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  sort(A, A+N, greater<int>());

  lld ans = 0, num = 0;
  for (int i=0; i<N; i++) {
    num += A[i] - i;
    ans = max(ans, num);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
