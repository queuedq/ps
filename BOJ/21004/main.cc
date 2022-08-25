#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1'000'005;
lld cnt[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    fill(cnt, cnt+MN, 0);
    int n; cin >> n;
    for (int i=0; i<n; i++) { int a; cin >> a; cnt[a]++; }

    lld ans = 0;
    for (int i=1; i<MN; i++) {
      for (int j=i*2; j<MN; j+=i) {
        if ((i&j) == i) ans += (cnt[i^j] * cnt[j]);
      }
    }
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
