#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld K, D[100], S[100];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> K;

  D[0] = 1, D[1] = 1;
  S[0] = 1, S[1] = 2;
  int i;
  for (i = 2; i < 100; i++) {
    D[i] = S[i-2];
    S[i] = S[i-1] + D[i];
    if (K < S[i-1]) break;
  }
  i--; // K번째 이친수의 길이

  for (; i >= 1; i--) {
    if (K >= S[i-1]) { // K번째 이친수의 i번째 자리가 1
      K -= S[i-1];
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << endl;

  ////////////////////////////////
  return 0;
}
