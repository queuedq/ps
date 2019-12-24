#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 1e5 + 5;
lld N, x[MAX_N];

lld distance(lld k) {
  lld ret = 0;
  for (int i = 0; i < N; i++) {
    ret += abs(x[i] - i*k);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x[i];
  }

  lld l = 0, r = 3e9;
  while (r - l > 3) {
    lld mid = (l + r) / 2;
    if (distance(mid) < distance(mid + 1)) { r = mid + 1; }
    else { l = mid; }
  }

  lld ans = LLONG_MAX;
  for (lld p = l; p < r; p++) {
    ans = min(ans, distance(p));
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
