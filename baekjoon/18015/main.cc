#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MOD = 1e9;
const int MN = 2005;
int N, B, D[MN][MN][2][2];

int dp(int i, int j, int a, int b) {
  if (D[i][j][a][b] != -1) return D[i][j][a][b];
  if (i == N) return D[i][j][a][b] = a&b;
  
  D[i][j][a][b] = 0;
  if (j > 0) D[i][j][a][b] += dp(i+1, j-1, a|(j-1==0), b);
  if (j < B-1) D[i][j][a][b] += dp(i+1, j+1, a, b|(j+1==B-1));
  return D[i][j][a][b] = D[i][j][a][b] % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> B;

  for (int i=1; i<=N; i++) {
    for (int j=0; j<B; j++) {
      D[i][j][0][0] = D[i][j][0][1] = D[i][j][1][0] = D[i][j][1][1] = -1;
    }
  }

  int ans = 0;
  for (int j=1; j<B; j++) {
    ans = (ans + dp(1, j, j == 0, j == B-1)) % MOD;
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
