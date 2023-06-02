#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
// visible:
// - gcd(x, y) = 1
// - x^2 + y^2 < 1/R^2

const lld MR = 1e6;
int prime[MR], mobius[MR];
lld N, R;

void solve(int test) {
  cin >> N >> R;
  N = min(N-1, MR-1);
  double r = (double)MR / R;

  lld ans = 2;
  for (lld d=1; d<=N; d++) {
    lld circle = 0;
    for (lld x=1; x<=N/d; x++) {
      if (r*r/(d*d) - x*x <= 0) break;
      circle += min(N/d, (lld)ceil(sqrt(r*r/(d*d) - x*x)) - 1);
    }
    ans += circle * mobius[d];
  }

  cout << "Case #" << test << ": " << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  fill(prime+2, prime+MR, 1);
  fill(mobius, mobius+MR, 1);
  for (lld i=2; i<MR; i++) {
    if (!prime[i]) continue;
    mobius[i] = -1;
    for (lld j=i*2; j<MR; j+=i) prime[j] = 0, mobius[j] *= -1;
    for (lld j=i*i; j<MR; j+=i*i) mobius[j] = 0;
  }

  int T; cin >> T;
  for (int t=1; t<=T; t++) solve(t);

  ////////////////////////////////
  return 0;
}
