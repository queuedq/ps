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

  int n, w = 0, h = 0, dir = 0, pos = 0;
  cin >> n;

  //  [dir]    [pos]
  //
  //    1      2 - 1
  //  2 + 0    |   |
  //    3      3 - 0

  for (int i=0; i<n; i++) {
    if (pos == dir || pos == (dir+1) % 4) {
      if (dir % 2 == 0) { w++; cout << 1 << " "; }
      else { h++; cout << 1 << " "; }
    } else {
      if (dir % 2 == 0) { cout << ++w << " "; }
      else { cout << ++h << " "; }
      if (pos == (dir+2) % 4) pos = (pos+3) % 4;
      else pos = (pos+1) % 4;
    }

    int _, t; cin >> _ >> t;
    if (t == 1) dir = (dir+1) % 4;
    else dir = (dir+3) % 4;
  }

  ////////////////////////////////
  return 0;
}
