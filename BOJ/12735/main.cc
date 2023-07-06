#include <algorithm>
#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;
const int MN = 505;
lld N, K, l[MN], r[MN], D[MN][MN*2];
vector<lld> xs;
lld inv[MN], binom[MN][MN], C[MN], cnt[MN*2][MN];

lld mpow(lld a, lld e) {
  if (e == 0) return 1;
  lld r = mpow(a, e/2);
  r = r*r % MOD;
  return r * (e%2 ? a : 1) % MOD;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    cin >> l[i] >> r[i];
    r[i]++;
  }

  // compress
  xs.push_back(0);
  for (int i=1; i<=N; i++) {
    xs.push_back(l[i]);
    xs.push_back(r[i]);
  }

  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());

  for (int i=1; i<=N; i++) {
    l[i] = lower_bound(all(xs), l[i]) - xs.begin();
    r[i] = lower_bound(all(xs), r[i]) - xs.begin();
  }
  K = sz(xs);

  // precompute cnt
  // cnt[k][i]: cnt for i variables in [xs[k], xs[k+1])
  //            where last variable is always used
  for (int i=1; i<=N; i++) inv[i] = mpow(i, MOD-2);
  for (int i=0; i<=N; i++) {
    binom[i][0] = 1;
    for (int j=1; j<=i; j++) binom[i][j] = (binom[i-1][j-1] + binom[i-1][j]) % MOD;
  }

  for (int k=0; k<K-1; k++) {
    C[0] = 1;
    for (int i=1; i<=N; i++) {
      C[i] = (C[i-1] * (xs[k+1]-xs[k] - i+1)) % MOD;
      C[i] = (C[i] * inv[i]) % MOD;
    }

    for (int i=1; i<=N; i++)
      for (int j=0; j<=i-1; j++) // select j among i-1 variables
        cnt[k][i] = (cnt[k][i] + binom[i-1][j] * C[j+1]) % MOD;
  }

  // DP
  for (int k=0; k<K; k++) D[0][k] = 1;
  for (int i=1; i<=N; i++) {
    for (int k=l[i]; k<r[i]; k++) { // i-th boat in [xs[k], xs[k+1])
      for (int j=i, t=0; j>=1; j--) {
        // [j, i]-th boat in the same range ((j-1)-th is lower)
        if (l[j] <= k && k < r[j]) t++; // selectable variables
        D[i][k] = (D[i][k] + D[j-1][k-1] * cnt[k][t]) % MOD;
      }
    }
    for (int k=1; k<K; k++) D[i][k] = (D[i][k] + D[i][k-1]) % MOD; // psum
  }

  lld ans = 0;
  for (int i=1; i<=N; i++) ans = (ans + D[i][K-1]) % MOD;
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
