#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

void solve(int test) {
  lld R, ans = 0; cin >> R;
  for (lld x=-R+1; x<=R-1; x++) {
    lld y = sqrt(R*R - x*x - 1);
    ans += y*2 + 1;
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
