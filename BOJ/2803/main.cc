#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;
int N, M, A[1<<20], D[1<<20][21];

lld powmod(lld a, lld e) {
  lld r = 1;
  for (; e > 0; e /= 2) {
    if (e & 1) r = r*a % MOD;
    a = a*a % MOD;
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) {
    int K; cin >> K;
    int m = 0;
    for (int j=0; j<K; j++) {
      int x; cin >> x;
      m += 1<<(x-1);
    }
    A[m]++;
  }

  for (int m=0; m<1<<M; m++) {
    D[m][0] = A[m];
    for (int i=1; i<=M; i++) {
      D[m][i] = D[m][i-1];
      if (m>>(i-1) & 1) D[m][i] += D[m ^ 1<<(i-1)][i-1];
    }
  }

  lld ans = 0;
  for (int m=0; m<1<<M; m++) {
    int p = 0;
    for (int i=0; i<M; i++) p += m>>i & 1;
    if ((M+p) & 1) ans -= powmod(2, D[m][M]);
    else ans += powmod(2, D[m][M]);
    ans = (ans % MOD + MOD) % MOD;
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
