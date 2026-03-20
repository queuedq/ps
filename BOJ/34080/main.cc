#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N, x, y;

// equivalent to moving one stone each at a time
// weight sum is preserved
void solve() {
  cin >> N >> x >> y;

  lld sum = y * N;
  lld q = sum / (x+y);
  lld r = sum % (x+y);

  if (r == 0) {
    cout << 1 << endl;
    cout << q << " " << (x+y) << endl;
  } else {
    cout << 2 << endl;
    cout << q << " " << (x+y-r) << endl;
    cout << (q+1) << " " << r << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int Q; cin >> Q;
  while (Q--) solve();

  ////////////////////////////////
  return 0;
}
