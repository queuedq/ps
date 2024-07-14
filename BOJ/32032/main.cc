#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
lld N, D, X[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> D;
  lld l = 0, r = 0;
  for (int i=0; i<N; i++) {
    cin >> X[i];
    l = max(l, -X[i]);
    r = max(r, X[i]);
  }

  lld ans = LLONG_MAX;
  // LRRL
  ans = min(ans, (l+l+r)*2 + D);
  // RLLR
  ans = min(ans, (l+r+r)*2 + D);
  // LRLR | RLRL
  lld extra = max(0LL, D - (l+r)*2); // LR(here)LR
  ans = min(ans, (l+l+r+r)*2 + extra);
  // LLRR | RRLL
  ans = min(ans, (l+r)*2 + D*2);

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
