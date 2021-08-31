#include <bits/stdc++.h>
#define endl "\n"
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
  lld mn = INT_MAX, mx = INT_MIN, sum = 0, px, py, x0, x1;
  for (int i=0; i<N; i++) {
    lld x, y; cin >> x >> y;
    mn = min(mn, x - y);
    mx = max(mx, x - y);
    if (i > 0) sum += abs(x - px) + abs(y - py);
    px = x;
    py = y;
    if (i == 0) x0 = x;
    if (i == N-1) x1 = x;
  }

  cout << sum - (mx-mn) + max(x0-mn, 0LL) + max(mx-x1, 0LL) << endl;

  ////////////////////////////////
  return 0;
}
