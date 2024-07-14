#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 998'244'353;
const int MN = 1e6+5;
lld N, fact[MN], ifact[MN], ans[MN];
map<int, int> cnt;

lld pow(lld x, lld e) {
  if (e == 0) return 1;
  lld y = pow(x, e/2);
  y = y * y % MOD;
  if (e%2 == 0) return y;
  return y * x % MOD;
}

lld binom(lld n, lld k) {
  return fact[n] * ifact[k] % MOD * ifact[n-k] % MOD;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int k; cin >> k;
    while (k--) { int x; cin >> x; cnt[x]++; }
  }

  fact[0] = ifact[0] = 1;
  for (int i=1; i<=N; i++) {
    fact[i] = fact[i-1] * i % MOD;
    ifact[i] = pow(fact[i], MOD-2);
  }

  for (auto [_, c]: cnt) {
    for (int i=1; i<=c; i++) ans[i] = (ans[i] + binom(c, i)) % MOD;
  }

  for (int i=1; i<=N; i++) cout << ans[i] << endl;

  ////////////////////////////////
  return 0;
}
