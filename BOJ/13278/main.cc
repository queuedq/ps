#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld pow(lld a, lld e, lld m) {
  if (e == 0) return 1;
  lld x = pow(a, e/2, m);
  return (x*x % m) * (e%2 ? a : 1) % m;
}

////////////////////////////////////////////////////////////////
const lld MN = 50005;
const lld MOD = 99991;
// Fibonacci sequence = (a^n * p + b^n * q)
const lld a = 44944, b = 55048;
const lld p = 77972, q = 22019;

int N, K;
lld S[MN], D[MN], E[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) cin >> S[i];

  D[0] = E[0] = 1;
  
  for (int i=1; i<=N; i++) {
    lld c = pow(a, S[i], MOD);
    lld d = pow(b, S[i], MOD);
    for (int j=min(i, K); j>0 && j>=i-N+K; j--) {
      D[j] = (D[j] + D[j-1]*c) % MOD;
      E[j] = (E[j] + E[j-1]*d) % MOD;
    }
  }

  cout << (D[K]*p + E[K]*q) % MOD << endl;

  ////////////////////////////////
  return 0;
}
