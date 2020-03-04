#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;

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

class Fenwick {
public:
  vector<lld> arr;

  Fenwick(lld size) { arr.resize(size); }

  void reset() { fill(arr.begin(), arr.end(), 0); }

  lld query(lld i) {
    lld s = 0;
    while (i > 0) {
      s = (s+arr[i]) % MOD;
      i -= i & -i;
    }
    return s;
  }

  void update(lld i, lld val) {
    i++;
    while (i < arr.size()) {
      arr[i] = (arr[i]+val) % MOD;
      i += i & -i;
    }
  }
};

////////////////////////////////////////////////////////////////
const lld MAXN = 300'005;
lld n, p[MAXN], q;
lld pow2[MAXN], invpow2[MAXN];
Fenwick L(MAXN), R(MAXN);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  pow2[0] = 1; invpow2[0] = 1; invpow2[1] = invmod(2, MOD);
  for (int i=1; i<MAXN; i++) pow2[i] = pow2[i-1]*2 % MOD;
  for (int i=2; i<MAXN; i++) invpow2[i] = invpow2[i-1]*invpow2[1] % MOD;

  ////////

  cin >> n;
  for (int i=0; i<n; i++) cin >> p[i];

  for (int i=0; i<n; i++) L.update(i, p[i]*pow2[i] % MOD);
  for (int i=0; i<n; i++) R.update(i, p[i]*pow2[n-1-i] % MOD);

  lld E=0;
  for (int i=0; i<n; i++) {
    lld t=0;
    t += L.query(i) * invpow2[i+1] % MOD;
    t += (R.query(n)-R.query(i+1)) * invpow2[n-i] % MOD;
    t = (t * p[i]) % MOD;
    E = (E + t) % MOD;
  }
  E = E*invpow2[1] % MOD;

  cout << E << endl;

  ////////

  cin >> q;
  while (q--) {
    lld i,x; cin>>i>>x; i--;
    lld delta = (x-p[i]+MOD)%MOD;
    p[i] = x;
    L.update(i, delta*pow2[i]);
    R.update(i, delta*pow2[n-1-i]);

    lld t=0;
    t += L.query(i) * invpow2[i+1] % MOD;
    t += (R.query(n)-R.query(i+1)) * invpow2[n-i] % MOD;
    t = (t * delta) % MOD;
    E = (E + t) % MOD;

    cout << E << endl;
  }

  ////////////////////////////////
  return 0;
}
