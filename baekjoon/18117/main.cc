#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld pow10(lld e, lld mod) {
  __int128 a = 1, b = 10;
  while (e > 0) {
    if (e & 1) a = a*b % mod;
    e >>= 1;
    b = b*b % mod;
  }
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    lld a, b, s, l; cin >> a >> b >> s >> l;
    lld r = (__int128)a * pow10(s-1, b) % b;
    for (int i=0; i<l; i++) {
      cout << (lld)((__int128)r * 10 / b);
      r = (__int128)r * 10 % b;
    }
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
