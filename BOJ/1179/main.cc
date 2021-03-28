#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

lld solve(lld N, lld K) {
  if (N == 1) return 1;
  if (N < K) return (K + solve(N-1, K) - 1) % N + 1;

  lld r = N/K;
  lld s = solve(N-r, K);
  if (r*K + s <= N) return r*K + s;
  s -= N - r*K;
  return (s-1)/(K-1)*K + (s-1)%(K-1) + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  lld N, K;
  cin >> N >> K;
  if (K == 1) cout << N << endl;
  else cout << solve(N, K) << endl;

  ////////////////////////////////
  return 0;
}
