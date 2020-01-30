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

  int A, B, C; cin >> A >> B >> C;
  double l = 0, r = 200'000;

  while (r - l > 1e-12) {
    double x = (l + r) / 2;
    if (A*x + B*sin(x) > C) {
      r = x;
    } else {
      l = x;
    }
  }

  cout << fixed << setprecision(12) << (l + r) / 2 << endl;

  ////////////////////////////////
  return 0;
}
