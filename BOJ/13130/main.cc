#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, A[16], comp[1<<16], pop[1<<16], msb[1<<16], ok[1<<16];
lld fact[17], dp[1<<16];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  
  for (int m=0; m<1<<N; m++) {
    for (int i=0; i<N; i++) {
      if (m>>i & 1) { pop[m]++; msb[m] = 1<<i; }
    }

    ok[m] = true;
    for (int i=0; i<N; i++) {
      if ((m>>i & 1) && A[i] % pop[m] != 0) ok[m] = false;
    }
  }

  fact[0] = 1;
  for (int i=1; i<=N; i++) fact[i] = fact[i-1] * i;

  dp[0] = 1;
  for (int m=1; m<1<<N; m++) {
    for (int k = m ^ msb[m]; k > 0; k = (k-1) & m) {
      if (ok[m^k]) dp[m] += fact[pop[m^k] - 1] * dp[k];
    }
    if (ok[m]) dp[m] += fact[pop[m] - 1];
  }

  cout << dp[(1<<N) - 1] << endl;

  ////////////////////////////////
  return 0;
}
