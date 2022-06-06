#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
using llf = long double;

////////////////////////////////////////////////////////////////
lld n, m, vst[1'000'005];

llf extrema(lld p) {
  return powl((llf)p / n, (llf)n / (n-1)) * (n-1);
}

lld odd() {
  lld ans = (m+1) * (m*2+1);

  for (lld a=1; ; a++) {
    llf p = n * powl(a, n-1);
    llf q = (n-1) * powl(a, n);
    if (p > m || q > m) break;
    vst[(lld)p] = 1;
    ans += 2 * (m - (lld)q);
  }

  for (lld p=1; p<=m; p++) {
    if (vst[p]) continue;
    llf e = extrema(p);
    if (e > m) break;
    ans += 2 * max(m - (lld)e, 0LL);
  }
  return ans;
}

lld even() {
  lld ans = 1;
  for (lld a=1; ; a++) {
    if (n * pow(a, n-1) > m || (n-1) * pow(a, n) > m) break;
    ans += 2;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n >> m;
  if (n%2) cout << odd() << endl;
  else cout << even() << endl;

  ////////////////////////////////
  return 0;
}
