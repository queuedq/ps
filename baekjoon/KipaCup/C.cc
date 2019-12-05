#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
int T;

lld gcd(lld a, lld b) {
  while (b > 0) {
    a = a % b;
    swap(a, b);
  }
  return a;
}

pll xgcd(lld a, lld b) {
  lld ax = 1, ay = 0, bx = 0, by = 1;
  while (b > 0) {
    lld q = a / b;
    a -= b * q; ax -= bx * q; ay -= by * q;
    swap(a, b); swap(ax, bx); swap(ay, by);
  }
  return {ax, ay};
}

lld modinv(lld a, lld p) {
  return (xgcd(a, p).first % p + p) % p;
}

pll calc(lld a, lld b) {
  lld g = gcd(a, b);
  a /= g; b /= g;
  while (b % 2 == 0) b /= 2;
  if (b == 1) return {1, 1}; // finite digits => 0.11111...
  lld aa = a;
  lld bits = 0, cycle = 0;
  do {
    // cout << a << " ";
    a <<= 1;
    aa <<= 2;
    if (a >= b) bits++;
    a %= b;
    aa %= b;
    cycle++;
  } while (aa != a);
  // cout << a << endl;
  lld gg = gcd(bits, cycle);
  return {bits / gg, cycle / gg};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> T;
  for (int t = 0; t < T; t++) {
    lld a, b; cin >> a >> b;
    pll ratio = calc(a, b);
    cout << ratio.first << "/" << ratio.second << endl;
  }

  ////////////////////////////////
  return 0;
}
