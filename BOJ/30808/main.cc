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

void fft(vector<lld> &f, bool inv) {
	int n = sz(f), L = 31 - __builtin_clz(n);
  static vector<lld> rt(2, 1);
  static vector<lld> irt(2, 1);
  for (static int k=2; k<n; k*=2) {
    rt.resize(n); irt.resize(n);
    lld x = modpow(3, (MOD-1)/(k*2), MOD);
    lld ix = modpow(x, MOD-2, MOD);
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
		lld z = modpow(n, MOD-2, MOD);
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
  return f;
}

////////////////////////////////////////////////////////////////
const int X = 1e6+5;
lld N, fact[X], ifact[X];
map<int, int> cnt;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    lld l, r; cin >> l >> r;
    cnt[l]++; cnt[r+1]--;
  }

  // prefix sum
  vector<lld> A(X);
  for (auto it=cnt.begin(); it!=cnt.end(); it++) {
    auto [x, c] = *it;
    auto [y, _] = *next(it);
    next(it)->second += it->second;
    if (it != cnt.end()) A[c] += y-x; // number of (cnt[*] == c)
  }

  // prepare polynomials
  fact[0] = ifact[0] = 1;
  for (int i=1; i<X; i++) {
    fact[i] = fact[i-1] * i % MOD;
    ifact[i] = modpow(fact[i], MOD-2, MOD);
  }

  vector<lld> B(X);
  for (int i=0; i<X; i++) {
    A[i] = A[i] * fact[i] % MOD;
    B[i] = ifact[X-i-1];
  }

  // fft
  vector<lld> ans = conv(A, B);
  for (int i=0; i<X; i++) ans[i+X-1] = ans[i+X-1] * ifact[i] % MOD;

  for (int i=1; i<=N; i++) cout << ans[i+X-1] << endl;

  ////////////////////////////////
  return 0;
}
