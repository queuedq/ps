#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MOD = 10007;
const int MN = 1010;
int N, D[MN][MN];
string S;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> S;
  N = sz(S);
  for (int i=N-1; i>=0; i--) {
    D[i][i] = 1;
    for (int j=i+1; j<N; j++) {
      D[i][j] = D[i][j-1] + D[i+1][j] - D[i+1][j-1];
      if (S[i] == S[j]) D[i][j] += D[i+1][j-1] + 1;
      D[i][j] %= MOD;
      if (D[i][j] < 0) D[i][j] += MOD;
    }
  }
  cout << D[0][N-1] << endl;

  ////////////////////////////////
  return 0;
}
