#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1000000009;
lld N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  lld ans = 1;
  for (lld i = 0; i < N; i++) {
    ans = ans * (2*i+1) % MOD;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
