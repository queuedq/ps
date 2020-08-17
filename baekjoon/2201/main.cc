#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld K, D[100][2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> K;
  if (K == 1) { cout << 1 << endl; return 0; }
  K++; // include 0

  D[1][0] = D[1][1] = 1;

  int i=2;
  while (true) {
    D[i][0] = D[i-1][0] + D[i-1][1];
    D[i][1] = D[i-1][0];
    if (D[i][0] + D[i][1] >= K) break;
    i++;
  }

  int digit = 0;
  for (; i >= 1; i--) {
    if (digit == 1) {
      digit = 0;
    } else {
      if (K <= D[i][0]) { digit = 0; }
      else { digit = 1; K -= D[i][0]; }
    }
    cout << digit;
  }
  cout << endl;

  ////////////////////////////////
  return 0;
}
