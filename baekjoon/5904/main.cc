#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N, D[50];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;

  D[1] = 3;
  int i=2;
  while (true) {
    D[i] = D[i-1] * 2 + i+2;
    if (D[i] >= N) break;
    i++;
  }

  while (i > 0) {
    if (N <= D[i-1]) i--;
    else if (N == D[i-1] + 1) { cout << "m" << endl; return 0; }
    else if (N <= D[i-1] + i+2) { cout << "o" << endl; return 0; }
    else { N -= D[i-1] + i+2; i--; }
  }

  ////////////////////////////////
  return 0;
}
