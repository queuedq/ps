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

////////////////////////////////////////////////////////////////
const int MN = 105;
const int MD = 5000;
const lld MOD = INT_MAX;
lld N, K, fac[MN], ifac[MN];
vector<lld> dvs;
unordered_map<lld, int> idx;
lld D[MN][MD];

lld dp(int n, lld k) {
  if (n == 0) return k == K;
  if (D[n][idx[k]] != -1) return D[n][idx[k]];
  lld &res = D[n][idx[k]] = 0;
  for (auto d: dvs) {
    if (d > n) break;
    res = (res + (fac[n-1] * ifac[n-d] % MOD) * dp(n-d, lcm(k, d))) % MOD;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;
  fac[0] = ifac[0] = 1;
  for (int i=1; i<=N; i++) {
    fac[i] = fac[i-1] * i % MOD;
    ifac[i] = modinv(fac[i], MOD);
  }

  for (lld d=1; d*d<=K; d++) {
    if (K%d == 0) {
      dvs.push_back(d);
      if (d*d != K) dvs.push_back(K/d);
    }
  }
  sort(all(dvs));
  for (int i=0; i<sz(dvs); i++) idx[dvs[i]] = i;

  memset(D, -1, sizeof(D));
  cout << dp(N, 1) << endl;

  ////////////////////////////////
  return 0;
}
