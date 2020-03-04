#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int t, n, m, a[1005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> t;
  while (t--) {
    cin >> n >> m;
    int tot = 0;
    for (int i = 0; i<n; i++) {
      cin >> a[i];
      tot += a[i];
    }
    cout << min(tot, m) << endl;
  }


  ////////////////////////////////
  return 0;
}
