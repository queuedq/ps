#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 2e5 + 5;
const lld MOD = 998244353;
lld N, P[MAX_N];

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> P[i];
    P[i] = P[i] * modinv(100, MOD) % MOD;
  }

  lld E = 0;
  for (int i = 0; i < N; i++) {
    E = (E + 1) * modinv(P[i], MOD) % MOD;
  }

  cout << E << endl;

  ////////////////////////////////
  return 0;
}
