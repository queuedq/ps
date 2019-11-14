#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
void check(bool b) {
  if (b) { cout << "YES" << endl; }
  else { cout << "NO" << endl; }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int x, y;
    cin >> x >> y;
    if (x == 1) {
      check(y == 1);
    } else if (x == 2 || x == 3) {
      check(y == 1 || y == 2 || y == 3);
    } else {
      check(true);
    }
  }

  ////////////////////////////////
  return 0;
}
