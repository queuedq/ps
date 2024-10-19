#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////
const lld MOD = 998'244'353;

lld modpow(lld x, lld e, lld m) {
  lld r = 1;
  for (; e; x = x*x % m, e/=2)
    if (e&1) r = r*x % m;
  return r;
}

lld modinv(lld x, lld m) { return modpow(x, m-2, m); }

void fft(vector<lld> &f, bool inv) {
  int n = sz(f), L = 31 - __builtin_clz(n);
  static vector<lld> rt(2, 1);
  static vector<lld> irt(2, 1);
  for (static int k=2; k<n; k*=2) {
    rt.resize(n); irt.resize(n);
    lld x = modpow(3, (MOD-1)/(k*2), MOD);
    lld ix = modinv(x, MOD);
    for (int i=k; i<2*k; i++) {
      rt[i] = (i&1) ? rt[i/2] * x % MOD : rt[i/2];
      irt[i] = (i&1) ? irt[i/2] * ix % MOD : irt[i/2];
    }
  }

  vector<int> rev(n);
  for (int i=0; i<n; i++) rev[i] = (rev[i/2] | (i&1)<<L) / 2;
  for (int i=0; i<n; i++) if (i < rev[i]) swap(f[i], f[rev[i]]);

  for (int k=1; k<n; k*=2) {
    for (int i=0; i<n; i+=2*k) {
      for (int j=0; j<k; j++) {
        lld u = f[i+j], v = f[i+j+k] * (inv ? rt[j+k] : irt[j+k]) % MOD;
        f[i+j] = (u + v) % MOD;
        f[i+j+k] = (u - v + MOD) % MOD;
      }
    }
  }

  if (inv) {
    lld z = modinv(n, MOD);
    for (int i=0; i<n; i++) f[i] = f[i]*z % MOD;
  }
}

vector<lld> conv(const vector<lld> &a, const vector<lld> &b) {
  int m = sz(a) + sz(b) - 1;
  int L = 32 - __builtin_clz(m), n = 1<<L;

  vector<lld> f(all(a)), g(all(b));
  f.resize(n); g.resize(n);

  fft(f, 0); fft(g, 0);
  for (int i=0; i<n; i++) f[i] *= g[i];
  fft(f, 1);
  f.resize(m);
  return f;
}

////////////////////////////////////////////////////////////////
const int MX = 1e5+5;
lld N, A[MX];

vector<lld> poly[MX];

void dnc(int s, int e) {
  if (s+1 == e) return;
  int m = (s+e)/2;
  dnc(s, m);
  dnc(m, e);
  poly[s] = conv(poly[s], poly[m]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  sort(A, A+N);

  // P[X>x] = PI_i (1 - x/A[i])
  for (int i=0; i<N; i++) poly[i] = {1, -modinv(A[i], MOD)};
  dnc(0, N);

  // E[X] = INT_{0..A[0]} ( x * -d/dx P[X>x] ) dx
  lld E = 0;
  for (int i=0; i<=N; i++) {
    // C x^i ---> -i/(i+1) C x^(i+1)
    lld term = -i * modinv(i+1, MOD) % MOD;
    term = term * poly[0][i] % MOD;
    term = term * modpow(A[0], i+1, MOD) % MOD;
    if (term < 0) term += MOD;
    E = (E + term) % MOD;
  }
  cout << E << endl;

  ////////////////////////////////
  return 0;
}
