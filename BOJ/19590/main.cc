#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N, x[100'005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> x[i];

  sort(x, x+N);

  lld ans = x[N-1];
  for (int i=0; i<N-1; i++) ans -= x[i];

  if (ans >= 0) {
    cout << ans << endl;
  } else if (ans % 2 == 0) {
    cout << 0 << endl;
  } else {
    cout << 1 << endl;
  }

  ////////////////////////////////
  return 0;
}
