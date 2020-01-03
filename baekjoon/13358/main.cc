#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
lld phi(lld n) {
  lld res = n;
  for (lld p = 2; p * p <= n; p++) {
    if (n % p == 0) res = res / p * (p-1);
    while (n % p == 0) n /= p;
  }
  if (n == 1) return res;
  return res / n * (n-1);
}

lld powmod(lld a, lld e, lld m) {
  lld b = 1, f = 1;
  while (f < e) f <<= 1;
  while (f > 0) {
    b = b * b % m;
    if (e & f) b = b * a % m;
    f >>= 1;
  }
  return b;
}

lld exponial(lld n, lld m) {
  if (n == 1) return 1 % m;
  if (n == 2) return 2 % m;
  if (n == 3) return 9 % m;
  if (n == 4) return 262144 % m;

  if (m == 1) return 0;

  lld e = exponial(n - 1, phi(m)) + phi(m);
  return powmod(n, e, m);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  lld n, m; cin >> n >> m;
  cout << exponial(n, m) << endl;

  ////////////////////////////////
  return 0;
}
