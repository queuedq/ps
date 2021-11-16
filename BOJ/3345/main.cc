#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 30005;
const int MOD = 1e9+9;
string S;
int N, D[2][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> S;

  D[0][0] = 1;
  for (int i=1; i<=N; i++) {
    for (int j=i%2; j<=min(i, N-i); j+=2) {
      D[i&1][j] = 0;
      if (j > 0) D[i&1][j] += D[~i&1][j-1];
      if (S[N-i] != ')') D[i&1][j] += D[~i&1][j+1];
      D[i&1][j] %= MOD;
    }
  }

  cout << D[N&1][0] << endl;

  ////////////////////////////////
  return 0;
}
