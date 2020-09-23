#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAX = 10000;
lld N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  lld S0, S1; cin >> S0 >> S1 >> N;
  while (N--) {
    lld i; cin >> i;
    lld a = S0, b = S1;

    while (i > 0) {
      tie(a, b) = pll(b, abs(a-b));
      i--;

      lld skip = i/3;
      if (b != 0) skip = min(skip, a/(2*b));

      a -= 2*b * skip;
      i -= 3 * skip;
    }

    cout << a << endl;
  }

  ////////////////////////////////
  return 0;
}
