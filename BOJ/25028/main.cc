#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld modpow(lld b, lld e, lld m) {
  lld r = 1;
  for (; e; b = b*b % m, e/=2)
    if (e&1) r = r*b % m;
  return r;
}

////////////////////////////////////////////////////////////////
const lld MN = 1e12, MX = 6e4, MOD = 1e9+7;
lld N, X, A[MX], S[MX], T[MX];
// A[i]: original sequence
// S[i]: i's last pos / A[S[i]] = i
// T[i]: len-i groups's last pos / A[T[i]] = S[i]
// A: 1 2 2 3 3 4 4 4 5 5 5 6 6 6 6 7 7 7 7 8 8 8 8
// S: x   x   x     x     x       x       x       x
// T: x       x           x                       x

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  A[1] = 1, A[2] = 2;
  S[1] = 1;
  T[1] = 1;

  for (int i=2; i<MX; i++) {
    S[i] = S[i-1] + A[i];
    T[i] = T[i-1] + (S[i] - S[i-1]) * i;
    if (T[i] > MN) { X = i; break; }
    for (lld j=S[i-1]+1; j<=min(S[i], MX-1); j++) A[j] = i;
  }

  // cout << X << endl; // 51619 (< 6e4)
  // cout << S[X] << endl; // 31348066 (< 4e7)
  // cout << T[X] << endl; // 1000024745494 (> 1e12)

  cin >> N;
  lld ans = 1;
  for (int i=1;; i++) {
    if (T[i] <= N) {
      lld mul = 1;
      for (lld j=S[i-1]+1; j<=S[i]; j++) mul = mul * j % MOD;
      ans = ans * modpow(mul, i, MOD) % MOD;
      continue;
    }

    lld n = N - T[i-1];
    for (lld j=S[i-1]+1; j<=S[i]; j++) {
      if (i <= n) {
        ans = ans  * modpow(j, i, MOD) % MOD;
        n -= i;
        continue;
      }

      ans = ans * modpow(j, n, MOD) % MOD;
      break;
    }
    break;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
