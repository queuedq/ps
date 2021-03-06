#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  lld t, p, a, b, c; cin >> t;
  while (t--) {
    cin >> p >> a >> b >> c;
    lld x = p%a == 0 ? 0 : a - p%a;
    lld y = p%b == 0 ? 0 : b - p%b;
    lld z = p%c == 0 ? 0 : c - p%c;
    cout << min({x, y, z}) << endl;
  }

  ////////////////////////////////
  return 0;
}
