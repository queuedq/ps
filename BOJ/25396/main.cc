#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld egcd(lld a, lld b, lld &x, lld &y) {
	if (!b) return x = 1, y = 0, a;
	lld g = egcd(b, a%b, y, x);
	return y -= a/b * x, g;
}

lld modinv(lld a, lld m) {
  lld x, y;
  egcd(a, m, x, y);
  return (x + m) % m;
}

lld modpow(lld b, lld e, lld m) {
	lld r = 1;
	for (; e; b = b*b % m, e/=2)
		if (e&1) r = r*b % m;
	return r;
}

////////////////////////////////
const lld MOD = 998'244'353;

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
  return f;
}

////////////////////////////////////////////////////////////////
const int MN = 200'005;
lld N, A[MN], fact[MN*4], ifact[MN*4];
vector<lld> terms;

lld mul(initializer_list<lld> L) {
  lld res = 1;
  for (auto x: L) res = res*x % MOD;
  return res;
}

vector<lld> mul_all(vector<vector<lld>> &F) {
  for (int s=1; s<F.size(); s*=2) {
    for (int i=0; i+s<F.size(); i+=s*2) {
      F[i] = conv(F[i], F[i+s]);
    }
  }
  return F[0];
}

vector<lld> muladd() {
  // m
  vector<lld> a(all(terms));
  for (int m=1; m<N; m++) { // handle m=N separately
    a[m] = mul({a[m], fact[m], fact[N-m], fact[N-m-1]});
  }

  // k-m
  vector<lld> b(N+1);
  for (int i=0; i<=N; i++) b[i] = ifact[i];
  
  auto ans = conv(a, b);
  for (int k=0; k<N; k++) {
    ans[k+1] = mul({ans[k+1], N-k, N-k-1, fact[k], ifact[N], ifact[N-1]});
  }
  ans.resize(N+1);

  ans[N] = terms[N]; // m=N
  return ans;
}

vector<lld> addmul() {
  vector<lld> ans(N);
  for (int k=0; k<N; k++) {
    ans[k] = mul({terms[N-k], fact[k], fact[N*2-k-1], ifact[N*2-k*2-1]});
    ans[k] = mul({ans[k], ifact[N], ifact[N-1], fact[N-k], fact[N-k-1]});
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fact[0] = ifact[0] = 1;
  for (int i=1; i<MN*4; i++) {
    fact[i] = fact[i-1]*i % MOD;
    ifact[i] = modinv(fact[i], MOD);
  }

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  // m-terms sum
  vector<vector<lld>> fs;
  for (int i=0; i<N; i++) fs.push_back({1, A[i]});
  terms = mul_all(fs);
  terms.resize(N+1);
  terms[0] = 0;

  vector<lld> ma = muladd();
  vector<lld> am = addmul();
  for (int k=0; k<N; k++) cout << ma[k+1] << " \n"[k==N-1];
  for (int k=0; k<N; k++) cout << am[k] << " \n"[k==N-1];

  ////////////////////////////////
  return 0;
}
