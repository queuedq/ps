#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int LOG = 25;
lld pw[LOG+1], D[LOG+1]; // D[i]: even count for < 5^i

// compare a! and (5^k+a)! : 5^0 + ... + 5^k more zeros
lld solve(lld N, int k) { // 5^k * d <= N < 5^(k+1)
  if (N == 0) return 0;
  lld d = N / pw[k];
  lld ret = 0;
  for (int i=0; i<d; i++) {
    if (k%2 == 0) ret += D[k]; // 5^0 + ... + 5^k = even
    else ret += (i%2 == 0) ? D[k] : (pw[k] - D[k]);
  }

  N %= pw[k];
  if (k%2 == 1 && d%2 == 1) return ret + N - solve(N, k-1);
  return ret + solve(N, k-1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  pw[0] = 1;
  for (int i=1; i<=LOG; i++) pw[i] = pw[i-1] * 5;

  D[0] = 1;
  for (int i=1; i<=LOG; i++) {
    if (i%2 == 1) D[i] = D[i-1] * 5;
    else D[i] = D[i-1] * 3 + (pw[i-1] - D[i-1]) * 2;
  }

  while (true) {
    lld N; cin >> N;
    if (N == -1) break;
    cout << solve(N+1, LOG) << endl;
  }

  ////////////////////////////////
  return 0;
}
