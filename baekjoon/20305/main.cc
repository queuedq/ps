#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;
const int MN = 1e6+5;
lld N, Q, F[MN], A[MN];
lld event[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> Q;
  F[1] = 1;
  for (int i=2; i<=N+1; i++) F[i] = (F[i-1] + F[i-2]) % MOD;

  for (int i=0; i<Q; i++) {
    int l, r; cin >> l >> r;
    event[l] = (event[l] + 1) % MOD;
    event[r+1] = (event[r+1] - F[r-l+2] + MOD) % MOD;
    event[r+2] = (event[r+2] - F[r-l+1] + MOD) % MOD;
  }

  A[1] = event[1];
  cout << A[1] << " ";
  for (int i=2; i<=N; i++) {
    A[i] = (A[i-1] + A[i-2] + event[i]) % MOD;
    cout << A[i] << " ";
  }

  ////////////////////////////////
  return 0;
}
