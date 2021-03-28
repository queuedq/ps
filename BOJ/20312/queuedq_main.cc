#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using lld = long long;

const int MN = 500'001;
const lld MOD = 1e9+7;
lld N, A[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  for (int i=0; i<N-1; i++) cin >> A[i];

  lld s = 0, ans = 0;
  for (int i=1; i<N; i++) {
    s = (s * A[i-1] + A[i-1]) % MOD;
    ans = (ans + s) % MOD;
  }

  cout << ans << endl;

  return 0;
}
