#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;
const int MN = 305;
lld N, D[MN][MN][MN];

lld dp(int a, int b, int c) {
  lld &res = D[a][b][c];
  if (res != -1) return res;
  if (a+b+c == 3) return res = 1;
  res = 0;

  if (a > 1) {
    for (int i=0; i<a; i++) {
      if (i == 0 || i == a-1) res = (res + dp(a-1, b, c)) % MOD;
      else if (b == 0) res = (res + dp(i, a-i-1, c)) % MOD;
      else if (c == 0) res = (res + dp(i, b, a-i-1)) % MOD;
    }
  }

  if (b > 1) {
    for (int i=0; i<b; i++) {
      if (i == 0 || i == b-1) res = (res + dp(a, b-1, c)) % MOD;
      else if (c == 0) res = (res + dp(a, i, b-i-1)) % MOD;
      else if (a == 0) res = (res + dp(b-i-1, i, c)) % MOD;
    }
  }

  if (c > 1) {
    for (int i=0; i<c; i++) {
      if (i == 0 || i == c-1) res = (res + dp(a, b, c-1)) % MOD;
      else if (a == 0) res = (res + dp(c-i-1, b, i)) % MOD;
      else if (b == 0) res = (res + dp(a, c-i-1, i)) % MOD;
    }
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<=N; i++) for (int j=0; j<=N; j++) for (int k=0; k<=N; k++) D[i][j][k] = -1;

  lld ans = (N * dp(N-1, 0, 0)) % MOD;
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
