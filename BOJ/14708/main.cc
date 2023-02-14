#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld K;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////
  
  // S = a b + b c + c a = half the surface area
  // (upper bound) = 3 (cbrt(K)+1)^2
  // For some fixed `a`, (lower bound) = 2 a sqrt(K/a) + K/a
  // Brute force only when lower bound <= upper bound
  // When K = 10^18, we only search `a` in [996949, 1000001].

  cin >> K;

  lld cb = floor(cbrt((long double)K)) + 1;
  lld hi = 3 * cb * cb;

  lld a;
  for (a = 1; a <= cb; a++) {
    lld sq = (lld)floor(sqrt((long double)(K / a)));
    lld lo = 2 * a * sq + K / a;
    if (lo <= hi) break;
  }

  array<lld, 4> best = {LLONG_MAX, 0, 0, 0};
  for (; a <= cb; a++) {
    for (lld b = a; ; b++) {
      lld c = K / a / b;
      if (a * b * c < K) c++;
      if (c < b) break;
      lld S = a * b + b * c + c * a;
      best = min(best, {S, a, b, c});
    }
  }

  cout << best[1] << " " << best[2] << " " << best[3] << endl;

  ////////////////////////////////
  return 0;
}
