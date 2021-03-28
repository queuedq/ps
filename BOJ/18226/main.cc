#include <bits/stdc++.h>
#define endl "\n"
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
const lld MAXN = 1e6+5;
const lld MOD = 1e9+7;
lld N, M, a[MAXN], b[MAXN];
lld fact[MAXN], inv[MAXN];
lld r[MAXN];
bool vst[MAXN];

lld comb(lld n, lld r) {
  return (fact[n] * inv[r] % MOD) * inv[n-r] % MOD;
}

lld calc() {
  lld ans = 1, u = 0;
  for (int i=1; i<=M; i++) {
    lld cand = N-r[i];
    if (cand < b[i] || b[i] < u) return 0;
    ans = ans * comb(cand-u, b[i]-u) % MOD;
    u = b[i];
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=M; i++) {
    cin >> a[i] >> b[i];
  }

  fact[0] = 1;
  for (int i=1; i<=N; i++) fact[i] = fact[i-1] * i % MOD;
  inv[N] = invmod(fact[N], MOD);
  for (int i=N-1; i>=0; i--) inv[i] = inv[i+1] * (i+1) % MOD;

  for (int i=M; i>=1; i--) {
    r[i] = r[i+1];
    if (!vst[a[i]]) {
      vst[a[i]] = true;
      r[i]++;
    }
  }

  cout << calc() << endl;

  ////////////////////////////////
  return 0;
}
