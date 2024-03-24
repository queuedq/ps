#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505050;
lld N, X, F, x[MN], p[MN], a[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> X >> F;
  for (int i=0; i<N; i++) cin >> x[i] >> p[i] >> a[i];
  x[N] = X;

  map<lld, lld> S = {{p[0], min(a[0], F)}};
  lld sum = a[0], cost = 0;

  for (int i=1; i<=N; i++) {
    // pop front
    lld dst = x[i] - x[i-1];
    sum -= dst;

    while (!S.empty() && dst > 0) {
      auto it = S.begin();
      auto &[s, d] = *it;
      lld t = min(d, dst);

      d -= t, dst -= t, cost += s * t;
      if (d == 0) S.erase(it);
    }

    if (dst > 0) return cout << -1 << endl, 0;

    // insert
    sum += a[i];
    S[p[i]] += a[i];

    // pop back
    while (sum > F) {
      auto it = prev(S.end());
      auto &[s, d] = *it;
      lld t = min(d, sum-F);

      d -= t, sum -= t;
      if (d == 0) S.erase(it);
    }
  }

  cout << cost << endl;

  ////////////////////////////////
  return 0;
}
