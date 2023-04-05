#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld T, X, Y;

void solve() {
  cin >> X >> Y;
  vector<char> ans;

  lld dist = abs(X) + abs(Y);
  if (dist % 2 == 0) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  lld jump = 1;
  while (jump <= dist) jump *= 2;
  jump /= 2;

  while (jump > 0) {
    if (abs(X) > abs(Y)) {
      if (X > 0) {
        X -= jump;
        ans.push_back('E');
      } else {
        X += jump;
        ans.push_back('W');
      }
    } else {
      if (Y > 0) {
        Y -= jump;
        ans.push_back('N');
      } else {
        Y += jump;
        ans.push_back('S');
      }
    }
    jump /= 2;
  }

  for (int i=ans.size()-1; i>=0; i--) {
    cout << ans[i];
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> T;

  for (int i=1; i<=T; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }

  ////////////////////////////////
  return 0;
}
