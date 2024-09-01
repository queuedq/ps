#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9;
const int MN = 1010;
int W, H, x[MN], y[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> W >> H;
  for (int i=1; i<W; i++) cin >> x[i];
  for (int j=1; j<H; j++) cin >> y[j];

  sort(x+1, x+W);
  sort(y+1, y+H);
  x[W] = y[H] = INF;

  int i = 1, j = 1, ans = 0;
  while (i<W || j<H) {
    if (x[i] < y[j]) ans += x[i++] * (H-j+1);
    else ans += y[j++] * (W-i+1);
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
