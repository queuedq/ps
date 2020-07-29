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

  int t; cin >> t;
  while (t--) {
    int l, r; cin >> l >> r;
    if (l*2 <= r) {
      cout << l << " " << l*2 << endl;
    } else {
      cout << -1 << " " << -1 << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
