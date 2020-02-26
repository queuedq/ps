#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

int calc(int S, int K) {
  if (K % 2 == 1) return S % 2;
  if (S % (K+1) == K) return K;
  if (S % (K+1) % 2 == 0) return 0;
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int S, K; cin >> S >> K;
    cout << calc(S, K) << endl;
  }

  ////////////////////////////////
  return 0;
}
