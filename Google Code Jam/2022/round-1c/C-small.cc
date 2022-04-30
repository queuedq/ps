#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

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

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;
const int MN = 55;
lld N, K, fact[MN*MN/2], D[MN*MN/2][MN][MN]; // edges, vertices, components

inline lld binom2(int n) { return n*(n-1)/2; }

lld solve() {
  cin >> N >> K;
  D[0][0][0] = 1;

  for (lld e=1; e<=binom2(N); e++) {
    for (lld v=1; v<=N; v++) {
      for (lld c=1; c<=v/2; c++) {
        D[e][v][c] = 0;
        D[e][v][c] += D[e-1][v][c] * max(binom2(v) - e+1, 0LL);
        D[e][v][c] += D[e-1][v-1][c] * (v-1) * (N-v+1);
        if (v >= 2) D[e][v][c] += D[e-1][v-2][c-1] * binom2(N-v+2);
        D[e][v][c] %= MOD;
      }
    }
  }

  return D[binom2(N)][N][K];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fact[0] = 1;
  for (int i=1; i<=MN*MN/2; i++) fact[i] = fact[i-1] * i % MOD;

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    lld ans = solve();
    ans = ans * invmod(fact[binom2(N)], MOD) % MOD;
    cout << "Case #" << t << ": " << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
