#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
map<int, int> D; // max in [0, X]

int solve(int x, int y) {
  if (x == 0 && D.count(y)) return D[y];

  // jump maximally
  // distance of j jumps = p-1
  int p = 1, j = 0;
  while (p*2-1 <= y) p *= 2, j++;

  // reduce interval
  if (x >= p-1) return j + solve(x-(p-1), y-(p-1));

  // split interval
  int ans = max(solve(x, p-2), j + solve(0, y-(p-1)));
  if (x == 0) D[y] = ans; // memoize
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  D[0] = 0;

  int T; cin >> T;
  while (T--) {
    int x, y; cin >> x >> y;
    cout << solve(x, y) << endl;
  }

  ////////////////////////////////
  return 0;
}
