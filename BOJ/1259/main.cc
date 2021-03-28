#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  while (true) {
    cin >> s;
    if (s == "0") break;

    bool ok = true;
    for (int i=0; i<s.size(); i++) {
      if (s[i] != s[s.size()-1-i]) {
        ok = false;
        break;
      }
    }

    if (ok) cout << "yes" << endl;
    else cout << "no" << endl;
  }

  ////////////////////////////////
  return 0;
}
