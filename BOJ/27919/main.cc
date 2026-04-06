#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
string S;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> S;
  int uc = 0, dp = 0;
  for (auto c: S) {
    if (c == 'U' || c == 'C') uc++;
    if (c == 'D' || c == 'P') dp++;
  }

  string ans = "";
  if (uc > (dp+1)/2) ans += "U";
  if (dp > 0) ans += "DP";
  if (ans == "") ans = "C";

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
