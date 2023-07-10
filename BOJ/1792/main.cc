#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 50005;
lld prime[MN], mu[MN], M[MN];
vector<lld> P;

void solve() {
  lld a, b, d; cin >> a >> b >> d;
  a /= d, b /= d;

  lld ans = 0;
  for (lld d=1; d<=a && d<=b;) {
    lld nd = min(a/(a/d)+1, b/(b/d)+1);
    ans += (M[nd-1] - M[d-1]) * (a/d) * (b/d);
    d = nd;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  fill(prime+2, prime+MN, 1);
  mu[1] = M[1] = 1;
  for (lld i=2; i<MN; i++) {
    if (prime[i]) {
      P.push_back(i);
      mu[i] = -1;
    }
    for (auto p: P) {
      if (i*p >= MN) break;
      prime[i*p] = 0;

      if (i%p == 0) { mu[i*p] = 0; break; }
      mu[i*p] = -mu[i];
    }
    M[i] = M[i-1] + mu[i];
  }

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
