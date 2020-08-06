#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld gcd(lld a, lld b) {
  return b == 0 ? a : gcd(b, a%b);
}

lld floorSum(lld p, lld q, lld n) { // sum_{i=1..n} floor(p*i/q)
  lld ans = (p/q) * n*(n+1)/2; // integer part of p/q
  p = p%q;

  if (p > 0) {
    ans += n * (p*n/q) - floorSum(q, p, p*n/q); // rectangle - triangle
    ans += n / (q/gcd(p, q)); // points on line
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int W; cin >> W;
  while (W--) {
    lld p, q, n; cin >> p >> q >> n;
    cout << p * n*(n+1)/2 - q * floorSum(p, q, n) << endl;
  }

  ////////////////////////////////
  return 0;
}
