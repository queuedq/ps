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

  lld A, B, C; cin >> A >> B >> C;

  lld r = 1, b = 1;
  while (b < B) b *= 2;
  while (b > 0) {
    r = r*r % C;
    if (B & b) r = r*A % C;
    b /= 2;
  }

  cout << r << endl;

  ////////////////////////////////
  return 0;
}
