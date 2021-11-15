#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N, K, fact[20];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fact[0] = 1;
  for (int i=1; i<20; i++) fact[i] = fact[i-1] * i;

  int T; cin >> T;
  while (T--) {
    int _; cin >> _ >> N >> K;
    lld ans = 0;

    for (int i=0; i<=K; i++) {
      ans += fact[N-i] * (fact[K] / fact[i] / fact[K-i]) * (i%2 == 0 ? 1 : -1);
    }

    cout << _ << " " << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
