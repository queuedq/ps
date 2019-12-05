#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;

  for (int i = 0; i < T; i++) {
    string s; cin >> s;
    bool success = true;

    for (int j = 0; j < s.size(); j++) {
      bool available[3] = {true, true, true};

      if (j > 0 && s[j - 1] == s[j] && s[j] != '?') { success = false; break; }
      if (s[j] == '?') {
        if (j > 0 && s[j - 1] != '?') {
          available[s[j - 1] - 'a'] = false;
        }
        if (j < s.size() - 1 && s[j + 1] != '?') {
          available[s[j + 1] - 'a'] = false;
        }
        for (int k = 0; k < 3; k++) {
          if (available[k]) {
            s[j] = 'a' + k;
            break;
          }
        }
      }
    }

    if (success) {
      cout << s << endl;
    } else {
      cout << -1 << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
