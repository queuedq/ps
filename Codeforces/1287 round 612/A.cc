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
  for (int i = 0; i < T; i++) {
    int k; cin >> k;
    string s; cin >> s;
    int cnt = INT_MIN;
    int ans = 0;
    for (char c: s) {
      if (c == 'P') {
        cnt++;
      } else {
        cnt = 0;
      }
      ans = max(ans, cnt);
    }
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
