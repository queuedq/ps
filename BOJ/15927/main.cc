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

  string s; cin >> s;
  int n = s.size();
  bool palin = true, same = true;
  for (int i = 0; i < n; i++) {
    if (s[i] != s[n-1-i]) palin = false;
    if (s[i] != s[0]) same = false;
  }

  if (same) { cout << -1 << endl; }
  else if (palin) { cout << n-1 << endl; }
  else { cout << n << endl; }

  ////////////////////////////////
  return 0;
}
