#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 2e5+5;

void calc() {
  string s; cin >> s;

  int ans = MAXN;

  for (int a=0; a<=9; a++) {
    int cnt = 0;
    for (int i=0; i<s.size(); i++) {
      if (s[i]-'0' == a) cnt++;
    }
    ans = min(ans, (int)s.size() - cnt);
  }

  for (int a=0; a<=9; a++) {
    for (int b=0; b<=9; b++) {
      if (a == b) continue;

      int cnt = 0;
      bool state = true;
      for (int i=0; i<s.size(); i++) {
        if (s[i]-'0' == a && state) {
          cnt++;
          state = false;
        } else if (s[i]-'0' == b && !state) {
          cnt++;
          state = true;
        }
      }

      if (!state) cnt--;

      ans = min(ans, (int)s.size() - cnt);
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int t; cin >> t;
  while (t--) {
    calc();
  }

  ////////////////////////////////
  return 0;
}
