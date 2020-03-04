#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;
const lld MAXN = 15e6+5;
bool isprime[MAXN];
lld n, m;

lld pow(lld a, lld e) {
  lld f = 1, b = a;
  while (e > 0) {
    if (e & 1) f = f*b % MOD;
    b = b*b % MOD;
    e >>= 1;
  }
  return f;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fill(isprime, isprime+MAXN, true);
  isprime[0] = isprime[1] = false;
  for (lld i = 2; i < MAXN; i++) {
    if (isprime[i]) {
      for (lld j = i*2; j < MAXN; j += i) {
        isprime[j] = false;
      }
    }
  }

  cin >> n >> m;

  lld ans = 1;
  for (lld i = 2; i <= max(n, m); i++) {
    if (!isprime[i]) continue;
    for (lld j = i; j <= max(n, m); j *= i) {
      ans = ans * pow(i, (n/j) * (m/j)) % MOD;
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
