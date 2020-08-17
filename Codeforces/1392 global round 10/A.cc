#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int T, N, A[200'005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> T;
  while (T--) {
    cin >> N;
    bool same = true;
    for (int i=0; i<N; i++) cin >> A[i];
    for (int i=1; i<N; i++) {
      if (A[i] != A[0]) {
        same = false;
        break;
      }
    }
    if (same) cout << N << endl;
    else cout << 1 << endl;
  }

  ////////////////////////////////
  return 0;
}
