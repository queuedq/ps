#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld fact[21];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fact[0] = 1;
  for (int i=1; i<=20; i++) {
    fact[i] = fact[i-1] * i;
  }
  long double e = exp(1.L);

  int T; cin >> T;
  for (int t=0; t<T; t++) {
    int N; cin >> N;
    // M A G I C
    cout << (lld)round((long double)fact[N] / e) << endl;
  }

  ////////////////////////////////
  return 0;
}
