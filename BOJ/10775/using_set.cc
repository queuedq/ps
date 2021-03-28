#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int G, P;
set<int> gates;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> G >> P;
  for (int i=1; i<=G; i++) gates.insert(-i);

  int ans = 0;
  for (; ans<P; ans++) {
    int g; cin >> g;
    auto it = gates.lower_bound(-g);
    if (it == gates.end()) break;
    gates.erase(it);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
