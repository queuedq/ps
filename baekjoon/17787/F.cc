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

  vector<int> ans;

  int k; cin >> k;
  for (int t=0; t<k; t++) {
    int n; cin >> n;

    set<int> seen;
    int alice = 1e9+5;
    bool ok = false;

    for (int i=0; i<n; i++) {
      int h; cin >> h;

      if (h > alice) ok = true;

      auto a = seen.upper_bound(h);
      if (a != seen.end()) {
        alice = min(alice, *a);
      }

      seen.insert(h);
    }
    if (ok) ans.push_back(t+1);
  }

  cout << ans.size() << endl;
  for (auto a: ans) {
    cout << a << endl;
  }

  ////////////////////////////////
  return 0;
}
