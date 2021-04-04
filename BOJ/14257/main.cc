#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

lld solve(lld S, lld X) {
  if (S == 0) return X == 0;
  if (S%2 != X%2) return 0;
  if (X%2 == 1) return 2 * solve(S/2, X/2);
  S /= 2; X /= 2;
  return S%2 == X%2 ? solve(S, X) : solve(S-1, X);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  lld S, X; cin >> S >> X;
  cout << solve(S, X) - (S == X) * 2 << endl;

  ////////////////////////////////
  return 0;
}
