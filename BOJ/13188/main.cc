#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2005;
const lld MOD = 1e9+7;
lld N, A, B, D[MN][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> A >> B;

  D[0][0] = 1;

  for (int i=1; i<=N; i++) {
    int cnt = (i > A) + (i > B);
    if (i == A || i == B) {
      for (int j=1; j<=N; j++) {
        D[i][j] += D[i-1][j] + D[i-1][j-1];
        D[i][j] %= MOD;
      }
    } else {
      for (int j=1; j<=N; j++) {
        D[i][j] += D[i-1][j+1] * j; // merge groups
        D[i][j] += D[i-1][j-1] * max(j - cnt, 0); // new group
        D[i][j] %= MOD;
      }
    }
  } 

  cout << D[N][1] << endl;

  ////////////////////////////////
  return 0;
}
