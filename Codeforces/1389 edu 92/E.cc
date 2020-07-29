#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

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

  int t; cin >> t;
  while (t--) {
    lld m, d, w; cin >> m >> d >> w;
    lld g = gcd(d-1, w);
    lld ww = w/g;

    lld c = min(m,d);
    lld q = c / ww, r = c % ww;
    cout << (ww-r) * q * (q-1) / 2 + r * (q+1) * q / 2 << endl;
  }

  ////////////////////////////////
  return 0;
}
