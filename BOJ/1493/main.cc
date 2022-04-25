#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld n, A[25], B[25], cnt[25];

void solve(lld x, lld y, lld z, int i) {
  if (x == 0 || y == 0 || z == 0) return;

  cnt[i] += (x/A[i]) * (y/A[i]) * (z/A[i]);
  lld xr = x%A[i], yr = y%A[i], zr = z%A[i];

  solve(xr, yr, zr, i-1);
  solve(x - xr, yr, zr, i-1);
  solve(xr, y - yr, zr, i-1);
  solve(xr, yr, z - zr, i-1);
  solve(x - xr, y - yr, zr, i-1);
  solve(x - xr, yr, z - zr, i-1);
  solve(xr, y - yr, z - zr, i-1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  lld x, y, z; cin >> x >> y >> z >> n;
  for (int i=1; i<=n; i++) {
    cin >> A[i] >> B[i];
    A[i] = 1<<A[i];
  }
  A[0] = 1;

  solve(x, y, z, n);

  lld ans = 0;
  for (int i=n; i>=1; i--) {
    lld m = (A[i] / A[i-1]);
    lld m3 = m * m * m;

    if (cnt[i] > B[i]) {
      cnt[i-1] += (cnt[i] - B[i]) * m3;
      cnt[i] = B[i];
    }

    ans += cnt[i];
  }
  
  if (cnt[0] > 0) { cout << -1 << endl; return 0; }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
