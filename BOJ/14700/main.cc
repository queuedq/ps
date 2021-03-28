#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;
lld N, M, D[2][1<<18];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  if (N < M) swap(N, M);
  
  fill(D[(N*M)&1], D[(N*M)&1] + (1<<M+1), 1);

  for (int i=N*M-1; i>=0; i--) {
    for (int s=0; s<1<<M+1; s++) {
      D[i&1][s] = 0;
      D[i&1][s] += D[~i&1][s>>1];
      if (i%M == 0 || !(s&1) || !(s&2) || !(s & 1<<M)) {
        D[i&1][s] += D[~i&1][s>>1 | 1<<M];
      }
      D[i&1][s] %= MOD;
    }
  }

  cout << D[0][0] << endl;

  ////////////////////////////////
  return 0;
}
