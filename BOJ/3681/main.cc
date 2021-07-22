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
    string S; cin >> S;
  
    unordered_map<lld, lld> cnt;
    lld n = 0, pow = 1, w = 0, dup = 0;

    for (char c: S) {
      if (c == '[') {
        pow *= 2;
      } else if (c == ',') {
        if (w != 0) {
          n++;
          dup = max(dup, ++cnt[w * pow]);
        }
        w = 0;
      } else if (c == ']') {
        if (w != 0) {
          n++;
          dup = max(dup, ++cnt[w * pow]);
        }
        w = 0;
        pow /= 2;
      } else {
        w = w * 10 + (c-'0');
      }
    }

    cout << n - dup << endl;
  }

  ////////////////////////////////
  return 0;
}
