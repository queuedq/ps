#include <bits/stdc++.h>
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  cout << "? " << 1 << " " << N << endl;
  int x; cin >> x;

  int l=1, r=N;
  while (l+1 < r) {
    int m = (l+r)/2;
    if (m >= x) cout << "? " << 1 << " " << m << endl;
    else cout << "? " << x-m+1 << " " << x << endl;
    int y; cin >> y;
    if (x == y) r = m;
    else l = m;
  }

  if (r > x) cout << "! " << r << endl;
  else cout << "! " << x-r+1 << endl;

  ////////////////////////////////
  return 0;
}
