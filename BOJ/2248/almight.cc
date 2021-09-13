#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 35;
lld N, L, l, D[MN][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> L >> l;

  fill(D[0], D[0]+N+1, 1);
  for (int i=1; i<=N; i++) {
    D[i][0] = 1;
    for (int j=1; j<=N; j++) {
      D[i][j] = D[i-1][j] + D[i-1][j-1];
    }
  }

  for (int i=N-1; i>=0; i--) {
    if (l <= D[i][L]) {
      cout << 0;
    } else {
      cout << 1;
      l -= D[i][L];
      L -= 1;
    }
  }

  ////////////////////////////////
  return 0;
}
