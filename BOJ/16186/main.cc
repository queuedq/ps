#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
long double A, B, C, D;

lld gcd(lld a, lld b) {
  while (b > 0) {
    a = a % b;
    swap(a, b);
  }
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> A >> B >> C >> D;
  lld ans = 0;
  for (lld p=1; p<1000; p++) {
    for (lld q=1; q<1000; q++) {
      if (p+q >= 1000) break;
      if (gcd(p, q) != 1) continue;
      lld l = max(ceil(A/p), ceil(C/q));
      lld r = min(floor(B/p), floor(D/q));
      if (l<=r) {
        ans += r-l+1;
      }
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
