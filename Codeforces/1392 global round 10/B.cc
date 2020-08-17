#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld T, N, K, A[200'005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> T;
  while (T--) {
    cin >> N >> K;
    lld mn = 2e9, mx = -2e9;
    for (int i=0; i<N; i++) {
      cin >> A[i];
      mn = min(mn, A[i]);
      mx = max(mx, A[i]);
    }

    if (K % 2 == 1) {
      for (int i=0; i<N; i++) cout << mx-A[i] << " ";
    } else {
      for (int i=0; i<N; i++) cout << A[i]-mn << " ";
    }
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
