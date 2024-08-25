#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
lld N, coins[MN][2];
lld ans = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N*2; i++) {
    lld x, y; cin >> x >> y;
    if (x < 1) ans += 1 - x, x = 1;
    if (x > N) ans += x - N, x = N;
    if (y < 1) ans += 1 - y, y = 1;
    if (y > 2) ans += y - 2, y = 2;
    coins[x][y-1]++;
  }

  int a = 0, b = 0; // (+: unmatched coins, -: unmatched goals) in each row
  for (int i=1; i<=N; i++) {
    a += coins[i][0] - 1;
    b += coins[i][1] - 1;
    while (a > 0 && b < 0) a--, b++, ans++;
    while (a < 0 && b > 0) a++, b--, ans++;
    if (i < N) ans += abs(a) + abs(b); // move coins or goals to next column
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
