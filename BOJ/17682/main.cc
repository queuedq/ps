#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 3030;
const lld MOD = 1e9+7;
int H, W;
lld D[MN][MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> H >> W;

  for (int h=0; h<=H; h++) {
    for (int w=0; w<=W; w++) {
      if (h == 0 || w == 0) { D[h][w] = 1; continue; }

      // last row
      D[h][w] += D[h-1][w]; // nothing
      D[h][w] += (w*4) * D[h-1][w-1]; // single
      if (w >= 2) D[h][w] += (w*(w-1)/2) * D[h-1][w-2]; // horizontal line
      if (h >= 2) D[h][w] += (w*(h-1)) * D[h-2][w-1]; // vertical line
      D[h][w] %= MOD;
    }
  }

  cout << D[H][W]-1 << endl;

  ////////////////////////////////
  return 0;
}
