#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MAXN = 505;
const lld MOD = 1e9+7;
lld N, D[2][MAXN][MAXN];
string farm[MAXN];

pii left(int len, int i) {
  return {i, len-i-1};
}

pii right(int len, int i) {
  return {N-len+i, N-i-1};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> farm[i];
  }

  D[0][0][0] = farm[0][0] == farm[N-1][N-1];

  for (int len=2; len<N; len++) {
    for (int i=0; i<len; i++) {
      auto [x, y] = left(len, i);
      for (int j=0; j<len; j++) {
        auto [z, w] = right(len, j);
        if (farm[x][y] == farm[z][w]) {
          if (i != len-1 && j != len-1) D[1][i][j] += D[0][i][j];
          if (i != len-1 && j != 0) D[1][i][j] += D[0][i][j-1];
          if (i != 0 && j != len-1) D[1][i][j] += D[0][i-1][j];
          if (i != 0 && j != 0) D[1][i][j] += D[0][i-1][j-1];
        }

        D[1][i][j] %= MOD;
      }
    }

    for (int i=0; i<=len; i++) for (int j=0; j<=len; j++) {
      D[0][i][j] = D[1][i][j];
      D[1][i][j] = 0;
    }
  }

  lld ans = D[0][0][0] + D[0][N-2][N-2];
  for (int i=1; i<N-1; i++) {
    ans += D[0][i][i] + D[0][i][i-1] + D[0][i-1][i] + D[0][i-1][i-1];
    ans %= MOD;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
