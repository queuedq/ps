#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
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

////////////////////////////////////////////////////////////////
const int MN = 55;
const lld MOD = 998'244'353;
lld N, K, P[MN], D[MN][MN][MN];
lld fac[MN], ifac[MN];

lld exp_term(int i, int cnt) {
  return (modpow(P[i], cnt, MOD) * ifac[cnt]) % MOD;
}

void solve(int t) {
  cin >> N >> K;
  if (N > 10 || K > 50) {
    cout << "Case #" << t << endl;
    cout << 0 << endl;
    return;
  }
  for (int i=1; i<=N; i++) cin >> P[i];

  for (int i=0; i<=N; i++) { // use types <= i
    D[i][0][0] = 1;
    for (int t=1; t<=i; t++) { // # selected types
      for (int k=t; k<=K; k++) { // # selected cards
        D[i][t][k] = D[i-1][t][k]; // don't use type i
        for (int l=1; l<=k; l++) { // use l cards of type i
          D[i][t][k] = (D[i][t][k] + D[i-1][t-1][k-l] * exp_term(i, l)) % MOD;
        }
      }
    }
  }

  lld ans = 0;
  for (int k=1; k<=K; k++) {
    lld E = 0;
    for (int t=1; t<=k; t++) E = (E + (D[N][t][k] * fac[k]) % MOD * t) % MOD;
    ans ^= E;
  }
  cout << "Case #" << t << endl;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fac[0] = ifac[0] = 1;
  for (int i=1; i<MN; i++) {
    fac[i] = fac[i-1] * i % MOD;
    ifac[i] = modinv(fac[i], MOD);
  }

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
