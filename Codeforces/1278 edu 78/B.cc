#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////

lld isqrt(lld x) {
  return floor(sqrt(x));
}

lld calc() {
  lld A, B; cin >> A >> B;
  if (A == B) return 0;
  if (A > B) swap(A, B);

  lld m = isqrt(2 * (B - A));

  for (int i = max(m - 10, 0LL); i < m + 10; i++) {
    lld range = A + i*(i+1)/2;
    if (range >= B && (range - B) % 2 == 0) {
      return i;
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    cout << calc() << endl;
  }

  ////////////////////////////////
  return 0;
}
