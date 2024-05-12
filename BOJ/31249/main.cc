#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

void solve() {
  int a, b; cin >> a >> b;
  if (a > b) swap(a, b);

  if (a == b) {
    //  _   | *AB
    // *A   |  B
    //  A   | *B
    // *AB  |  _
    cout << a << " " << 3 << endl;
    return;
  }

  if (a*2 >= b) {
    //  _     | *ABB
    // *A     |  BB
    //  A     | *BB
    // *AB    |  B
    //  B     | *AB
    // *BB    |  A
    //  BB    | *A
    // *ABB   |  _
    cout << a << " " << 7 << endl;
    return;
  }

  // same as above, with additional steps of bringing B one by one (along with all A's)
  int r = max(b - (a+1)*2, 0);
  int ans = 7 + r*2;
  // or just bring every B one by one
  ans = min(ans, b*2 - 1);

  cout << a+1 << " " << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
