#include "template.cc"

lld gcd(lld a, lld b) {
  while (b > 0) {
    a = a % b;
    swap(a, b);
  }
  return a;
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

lld powmod(lld a, lld e, lld m) {
  if (e < 0) { a = invmod(a, m); e = -e; }
  lld b = 1, f = 1;
  while (f < e) f <<= 1;
  while (f > 0) {
    b = b * b % m;
    if (e & f) b = b * a % m;
    f >>= 1;
  }
  return b;
}

lld phi(lld n) {
  lld res = n;
  for (lld p = 2; p * p <= n; p++) {
    if (n % p == 0) res = res / p * (p-1);
    while (n % p == 0) n /= p;
  }
  if (n == 1) return res;
  return res / n * (n-1);
}
