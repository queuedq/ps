#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505;
int N, K, D[MN][MN]; // #eggs, #tries -> max floor

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;

  int j;
  for (int i=1; i<=K; i++) {
    for (j=1; j<=MN; j++) {
      for (int k=0; k<j; k++) {
        D[i][j] += D[i-1][k] + 1;
      }
      if (D[i][j] >= N) break;
    }
  }

  cout << j << endl;

  ////////////////////////////////
  return 0;
}
