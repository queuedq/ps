#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MOD = 1e8+7;
const int MAX_P = 360000+5;
const int N = 360000;
int S, P, A[MAX_P], sym;
vector<int> angles, syms;

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

void getSymmetries() {
  for (int a = 1; a <= N; a++) {
    if (N % a != 0) continue;

    bool ok = true;
    for (int i = 0; i < a; i++) {
      for (int j = i; j < N; j += a) {
        if (angles[j] != angles[i]) {
          ok = false;
          break;
        }
      }
      if (!ok) break;
    }

    if (ok) syms.push_back(N / a);
  }

  sym = syms[0];
}

int calc(int d) {
  return powmod(S, P / d, MOD) * phi(d) % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  while (true) {
    cin >> S >> P;
    if (S == -1) { return 0; }

    angles.clear();
    angles.resize(360000);
    syms.clear();
    for (int i = 0; i < P; i++) {
      cin >> A[i];
      angles[A[i]] = 1;
    }

    getSymmetries();

    lld ans = 0;
    for (int d: syms) {
      ans = (ans + calc(d)) % MOD;
    }
    ans = ans * invmod(sym, MOD) % MOD;

    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
