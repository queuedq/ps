#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MOD = 9901;
const int MAXN = 15;
const int MAXP = (1 << 14);
int N, M, D[MAXN][MAXP];

void dp(int prv, int nxt, int m, int n) {
  if (m == M) {
    D[n][nxt] = (D[n][nxt] + D[n-1][prv]) % MOD;
    return;
  }

  dp(prv | (1<<m), nxt, m+1, n);
  dp(prv, nxt | (1<<m), m+1, n);
  if (M - m >= 2) dp(prv, nxt, m+2, n);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;

  D[0][0] = 1;
  for (int i=1; i<=N; i++) {
    dp(0, 0, 0, i);
  }

  cout << D[N][0] << endl;

  ////////////////////////////////
  return 0;
}
