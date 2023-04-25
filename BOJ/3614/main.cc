#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int N; cin >> N;
  lld ans = 0;

  for (int g=1; g<=N; g++) {
    if (N % g) continue;
    for (int a=1, b=N/g; a<=b; a++, b--) {
      if (gcd(a, b) == 1) ans++;
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
