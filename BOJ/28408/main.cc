#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 998'244'353;
const int MN = 505050;
int N, A[MN], B[MN], inv[MN];

lld dfs(int l, int r, int s, int e) {
  if (A[l] != B[e-1]) return 0;
  if (r-l <= 1) return 1;

  int t = inv[A[l+1]] + 1;
  if (t < s || t >= e) return 0;
  int len = t - s;

  if (t < e-1) { // two children
    return dfs(l+1, l+1 + len, s, t) * dfs(l+1 + len, r, t, e-1) % MOD;
  } else { // one child
    return 2 * dfs(l+1, l+1 + len, s, t) % MOD;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  for (int i=0; i<N; i++) {
    cin >> B[i];
    inv[B[i]] = i;
  }

  cout << dfs(0, N, 0, N) << endl;

  ////////////////////////////////
  return 0;
}
