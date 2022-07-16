#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 5e5+5;
const lld MOD = 1e9+7;
lld N, K, A[MN], S[MN], D[MN], fac[MN], ifac[MN];

lld comb(lld n, lld k) {
  if (k < 0 || k > n) return 0;
  return fac[n] * ifac[k] % MOD * ifac[n-k] % MOD;
}

lld pow(lld a, lld e) {
  if (e == 0) return 1;
  lld m = pow(a, e/2);
  return (m * m % MOD) * (e%2 ? a : 1) % MOD;
}

lld solve() {
  cin >> N >> K;
  for (int i=1; i<=N; i++) {
    cin >> A[i];
    S[i] = S[i-1] + A[i];
  }
  if (S[N] % K != 0) return 0;
  lld step = S[N] / K;

  if (step == 0) {
    lld cnt = 0;
    for (int i=1; i<=N-1; i++) cnt += S[i] == 0;
    // choose K-1 among cnt
    return comb(cnt, K-1);
  }

  fill(D, D+K, 0);
  D[0] = 1;
  for (int i=1; i<=N-1; i++) {
    if (S[i] % step != 0) continue;
    lld j = S[i] / step;
    if (j <= 0 || j >= K) continue;
    D[j] = (D[j] + D[j-1]) % MOD;
  }

  return D[K-1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fac[0] = ifac[0] = 1;
  for (int i=1; i<MN; i++) {
    fac[i] = fac[i-1] * i % MOD;
    ifac[i] = pow(fac[i], MOD-2);
  }

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    lld ans = solve();
    cout << "Case #" << t << endl;
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
