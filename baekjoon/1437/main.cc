#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MOD = 10'007;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int N; cin >> N;
  if (N <= 3) cout << N << endl;
  else {
    int ans;
    if (N % 3 == 0) ans = 3;
    else if (N % 3 == 1) ans = 4;
    else ans = 6;
    for (int i=0; i<N/3-1; i++) ans = ans * 3 % MOD;
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
