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

  int T; cin >> T;
  while (T--) {
    int a, b, x, y; cin >> a >> b >> x >> y;
    if (a == x) {
      cout << abs(b-y) << endl;
    } else if (b == y) {
      cout << abs(a-x) << endl;
    } else {
      cout << abs(a-x) + abs(b-y) + 2 << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
