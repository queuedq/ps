#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 250'000;
bool prime[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fill(prime, prime+MN, true);
  prime[0] = prime[1] = false;

  for (int i=2; i*i<MN; i++) {
    if (!prime[i]) continue;
    for (int j=i*2; j<MN; j+=i) prime[j] = false;
  }

  while (true) {
    int n; cin >> n;
    if (n == 0) break;
    int ans = 0;
    for (int i=n+1; i<=n*2; i++) ans += prime[i];
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
