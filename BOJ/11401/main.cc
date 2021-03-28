#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const lld MAX_N = 4e6;
const lld P = 1e9 + 7;
lld N, R;

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
  return (xgcd(a, p).first + p) % p;
}

lld factorial(lld n, lld p) {
  lld res = 1;
  while (n--) {
    res = res * (n+1) % p;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> R;
  lld comb = factorial(N, P);
  comb = comb * modinv(factorial(R, P), P) % P;
  comb = comb * modinv(factorial(N - R, P), P) % P;
  cout << comb << endl;

  ////////////////////////////////
  return 0;
}
