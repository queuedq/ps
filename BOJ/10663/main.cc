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
const int MX = 55;
int H, W;
char A[MX][MX];
int D[MX][MX][MX][MX];

inline bool match(char s, char e) {
  bool ok = ('a' <= s && s <= 'z') && ('A' <= e && e <= 'Z');
  return ok && (s-'a' == e-'A');
}

void solve() {
  cin >> H >> W;
  if (H == 0) return;

  for (int i=1; i<=H; i++) {
    for (int j=1; j<=W; j++) cin >> A[i][j];
  }

  // init DP
  for (int sx=0; sx<=H+1; sx++) for (int sy=0; sy<=W+1; sy++) {
    for (int ex=0; ex<=H+1; ex++) for (int ey=0; ey<=W+1; ey++) {
      D[sx][sy][ex][ey] = -INF;
    }
    if (A[sx][sy] != '#') D[sx][sy][sx][sy] = 0;
  }

  // DP
  // (sx, sy)
  for (int sx=H; sx>=1; sx--) for (int sy=W; sy>=1; sy--) {
    if (A[sx][sy] == '#') continue;

    // (ex, ey)
    for (int ex=sx; ex<=H; ex++) for (int ey=sy; ey<=W; ey++) {
      if (A[ex][ey] == '#') continue;

      // update DP
      auto &dp = D[sx][sy][ex][ey];

      dp = max(dp, D[sx+1][sy][ex][ey]);
      dp = max(dp, D[sx][sy+1][ex][ey]);
      dp = max(dp, D[sx][sy][ex-1][ey]);
      dp = max(dp, D[sx][sy][ex][ey-1]);

      if (match(A[sx][sy], A[ex][ey])) { // (a...A)
        if ((ex-sx) + (ey-sy) == 1) dp = 1;
        else {
          dp = max(dp, D[sx+1][sy][ex-1][ey] + 1);
          dp = max(dp, D[sx+1][sy][ex][ey-1] + 1);
          dp = max(dp, D[sx][sy+1][ex-1][ey] + 1);
          dp = max(dp, D[sx][sy+1][ex][ey-1] + 1);
        }
      }

      for (int x=sx; x<=ex; x++) for (int y=sy; y<=ey; y++) { // (...)(...)
        dp = max(dp, D[sx][sy][x][y] + D[x+1][y][ex][ey]);
        dp = max(dp, D[sx][sy][x][y] + D[x][y+1][ex][ey]);
      }

      // cout << "dp[" << sx << "][" << sy << "][" << ex << "][" << ey << "] = ";
      // cout << (dp >= 0 ? dp : -1) << endl;
    }
  }

  int ans = D[1][1][H][W];
  if (ans < 0) ans = -1;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  while (1) {
    solve();
    if (H == 0) break;
  }

  ////////////////////////////////
  return 0;
}
