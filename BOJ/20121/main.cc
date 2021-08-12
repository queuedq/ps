#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    lld N, A, B; cin >> N >> A >> B;
    A--; B--;

    lld i = 0, l = A, r = A+1, d;
    while (true) {
      d = (B%N - l%N + N) % N;
      if (d < r-l) break;
      i++; l*=2; r*=2;
    }
    
    for (int j=i-1; j>=0; j--) {
      if (d>>j & 1) cout << 'Y';
      else cout << 'X';
    }
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
