#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
lld N, a[MN], b[MN], c[MN], p[MN];

void solve() {
  cin >> N;
  for (int i=0; i<N; i++) cin >> a[i] >> b[i] >> c[i] >> p[i];

  lld A = 0, B = 0, C = 0, days = 0;
  for (int i=0; i<N; i++) {
    lld da = max(a[i] - A, 0LL);
    lld db = max(b[i] - B, 0LL);
    lld dc = max(c[i] - C, 0LL);
    A += da, B += db, C += dc;
    days += da + db + dc + 1;
    if (days > p[i]) { cout << "NO\n"; return; }
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
