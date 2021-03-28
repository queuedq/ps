#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N, K, P;

lld fact(lld a, bool mod) {
  lld res = 1;
  for (int i = 1; i <= a; i++) {
    res = res * i;
    if (mod) res %= P;
  }
  return res;
}

pll egcd(lld a, lld b) {
  lld ax = 1, ay = 0, bx = 0, by = 1;
  while (b > 0) {
    lld q = a / b;
    a -= b * q; ax -= bx * q; ay -= by * q;
    swap(a, b); swap(ax, bx); swap(ay, by);
  }
  return {ax, ay};
}

lld invmod(lld a, lld m) {
  return (egcd(a, m).first + m) % m;
}

lld calc() {
  if (N == 2) return N % P;
  if (N == 3) {
    if (K == 2) return fact(6, true);
    if (K == 3) return fact(720, true);
    return 0;
  }
  if (N <= 11) {
    if (K == 2) return fact(fact(N, false), true);
    return 0;
  }
  if (N == 12) {
    if (K == 2) {
      const lld fact12 = 479001600;
      if (P <= fact12) return 0;

      lld f = 1;
      for (int i = fact12+1; i < P; i++) f = f * i % P;
      return P-invmod(f, P);
    }
    return 0;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K >> P;
  cout << calc() << endl;

  ////////////////////////////////
  return 0;
}
