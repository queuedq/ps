#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9;
const int SQRT = 40'000;
int N, M;
bool prime[SQRT];
vector<int> A, B;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fill(prime+2, prime+SQRT, true);
  for (int i=2; i*i<SQRT; i++) {
    if (!prime[i]) continue;
    for (int j=i*2; j<SQRT; j+=i) prime[j] = false;
  }

  cin >> N;
  for (int i=0; i<N; i++) {
    int a; cin >> a;
    for (int j=2; j<SQRT; j++) {
      if (!prime[j]) continue;
      while (a%j == 0) {
        a /= j;
        A.push_back(j);
      }
    }
    if (a > 1) A.push_back(a);
  }

  cin >> M;
  for (int i=0; i<M; i++) {
    int b; cin >> b;
    for (int j=2; j<SQRT; j++) {
      if (!prime[j]) continue;
      while (b%j == 0) {
        b /= j;
        B.push_back(j);
      }
    }
    if (b > 1) B.push_back(b);
  }

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  lld ans = 1;
  bool overflow = false;
  while (!A.empty() && !B.empty()) {
    if (A.back() == B.back()) {
      ans *= A.back();
      if (ans >= MOD) {
        ans %= MOD;
        overflow = true;
      }
      A.pop_back();
      B.pop_back();
    } else if (A.back() > B.back()) {
      A.pop_back();
    } else {
      B.pop_back();
    }
  }

  if (!overflow) {
    cout << ans << endl;
  } else {
    for (int i=1e8; i>=1; i/=10) {
      cout << ans/i;
      ans %= i;
    }
  }

  ////////////////////////////////
  return 0;
}
