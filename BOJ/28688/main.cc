#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

void solve() {
  lld N, M; cin >> N >> M;
  bool win = 0;
  if (N <= 2 || M <= 2) win = 1;
  if (N%2 == 1 && M%2 == 1) win = 1;
  cout << (win ? "First" : "Second") << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
