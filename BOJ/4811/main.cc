#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N, D[35][35];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fill(D[0], D[0]+35, 1);
  for (int i=1; i<=30; i++) {
    for (int j=0; j<=30; j++) {
      if (i > 0) D[i][j] += D[i-1][j+1];
      if (j > 0) D[i][j] += D[i][j-1];
    }
  }

  while (true) {
    int N; cin >> N;
    if (N == 0) break;
    cout << D[N][0] << endl;
  }

  ////////////////////////////////
  return 0;
}
