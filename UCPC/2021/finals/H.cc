#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MOD = 1e9+7;
const int MN = 5e5+5;
lld N, H[MN], L[MN], D[MN], E[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> H[i];
  
  for (int i=1, l=0; i<=N; i++) {
    if (H[i] > H[l]) l = i;
    L[i] = l;
  }

  D[0] = E[0] = 1;
  for (int i=1; i<=N; i++) {
    D[i] = E[L[i]-1];
    E[i] = (E[i-1] + D[i]) % MOD;
  }

  cout << D[N] << endl;

  ////////////////////////////////
  return 0;
}
