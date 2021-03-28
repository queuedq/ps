#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

typedef __int128 llld;
typedef pair<llld, llld> plll;

////////////////////////////////////////////////////////////////
llld A, B, S;

plll xgcd(llld a, llld b) {
  llld ax = 1, ay = 0, bx = 0, by = 1;
  while (b > 0) {
    llld q = a / b;
    a -= b * q; ax -= bx * q; ay -= by * q;
    swap(a, b); swap(ax, bx); swap(ay, by);
  }
  return {ax, ay};
}

llld gcd(llld a, llld b) {
  plll x = xgcd(a, b);
  return a * x.first + b * x.second;
}

plll linear(llld a, llld b, llld c) { // a * x + b * y = c, x >= 0, x is min
  plll v = xgcd(a, b);
  llld x = v.first, y = v.second;
  llld g = a * x + b * y;
  if (c % g != 0) { return {-1, -1}; }
  a /= g; b /= g; c /= g;
  x *= c; y *= c;
  llld q = x / b;
  x -= b * q; y += a * q;
  if (x < 0) { x += b; y -= a; }
  // assert(a * x + b * y == c);
  // assert(x >= 0);
  // assert(x - b < 0);
  return {x, y};
}

bool check() {
  if (S == 0) { return A == 0 || B == 0; }
  if (A == 0 && B == 0) { return S == 0; }
  if (A == 0 || B == 0) { A = max(A, B); B = max(A, B); }

  plll v = linear(A, B, S);
  llld x = v.first, y = v.second;
  if (x == -1) return false;
  llld g = gcd(A, B);
  // assert(g > 0);
  A /= g; B /= g; S /= g;

  while (x <= S / A) {
    // assert(A * x + B * y == S);
    if (gcd(x, y) == 1) { return true; }
    x += B;
    y -= A;
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  lld AA, BB, SS;
  cin >> AA >> BB >> SS;
  A = AA; B = BB; S = SS;
  if (check()) { cout << "YES" << endl; }
  else { cout << "NO" << endl; }

  ////////////////////////////////
  return 0;
}
