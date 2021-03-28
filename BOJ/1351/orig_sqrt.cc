#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const lld SQRT_N = 1000005;
lld N, P, Q;
lld A[SQRT_N];

lld getA(lld i) {
  if (i < SQRT_N) return A[i];
  return getA(i / P) + getA(i / Q);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> P >> Q;
  A[0] = 1;
  for (lld i = 1; i < SQRT_N; i++) {
    A[i] = A[i / P] + A[i / Q];
  }
  cout << getA(N) << endl;

  ////////////////////////////////
  return 0;
}
