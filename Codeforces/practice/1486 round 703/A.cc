#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N, A[105];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    cin >> N;
    for (int i=0; i<N; i++) cin >> A[i];
    lld sum = 0, ans = true;
    for (int i=0; i<N; i++) {
      sum += A[i] - i;
      A[i] = i;
      if (sum < 0) ans = false;
    }
    cout << (ans ? "YES" : "NO") << endl;
  }

  ////////////////////////////////
  return 0;
}
