#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 200'005;
lld N, K, L[MN], R[MN];

int solve(int u, lld k) {
  if (L[u] == -1 && R[u] == -1) return u;
  if (L[u] == -1) return solve(R[u], k);
  if (R[u] == -1) return solve(L[u], k);
  if (k%2 == 0) return solve(R[u], k/2);
  else return solve(L[u], (k+1)/2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> L[i] >> R[i];
  cin >> K;
  cout << solve(1, K) << endl;

  ////////////////////////////////
  return 0;
}
