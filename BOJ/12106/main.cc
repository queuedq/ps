#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+9;
const int MN = 105;
lld L, N, fail[MN], D[MN][MN];
string S; 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> L >> S;
  N = S.size();

  for (int i=1, j=0; i<N; i++) {
    while (j > 0 && S[i] != S[j]) j = fail[j-1];
    if (S[i] == S[j]) fail[i] = ++j;
    else fail[i] = 0;
  }

  for (int j=0; j<N; j++) D[L][j] = 1;

  for (int i=L-1; i>=0; i--) {
    for (int j=0; j<N; j++) {
      for (int c=0; c<26; c++) {
        int k = j;
        while (k > 0 && S[k] != c+'a') k = fail[k-1];
        if (S[k] == c+'a') D[i][j] += D[i+1][k+1];
        else D[i][j] += D[i+1][0];
        D[i][j] %= MOD;
      }
    }
  }

  lld ans = 1;
  for (int i=0; i<L; i++) ans = ans*26 % MOD;
  ans = (ans - D[0][0] + MOD) % MOD;

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
