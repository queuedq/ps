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
vector<pii> holes[26];

inline bool is_lower(char c) { return 'a' <= c && c <= 'z'; }
inline bool is_upper(char c) { return 'A' <= c && c <= 'Z'; }
inline bool match(char s, char e) { return is_lower(s) && is_upper(e) && (s-'a' == e-'A'); }

void solve() {
  cin >> H >> W;
  if (H == 0) return;

  for (int i=0; i<26; i++) holes[i].clear();

  for (int i=1; i<=H; i++) {
    for (int j=1; j<=W; j++) {
      cin >> A[i][j];
      if (is_upper(A[i][j])) holes[A[i][j]-'A'].push_back({i, j});
    }
  }

  // init DP
  for (int sx=0; sx<=H+1; sx++) for (int sy=0; sy<=W+1; sy++) {
    for (int ex=0; ex<=H+1; ex++) for (int ey=0; ey<=W+1; ey++) {
      D[sx][sy][ex][ey] = -INF;
    }
    if (A[sx][sy] != '#') D[sx][sy][sx][sy] = 0;
  }

  // DP
  for (int sx=H; sx>=1; sx--) for (int sy=W; sy>=1; sy--) {
    for (int ex=sx; ex<=H; ex++) for (int ey=sy; ey<=W; ey++) {
      if (A[sx][sy] == '#' || A[ex][ey] == '#') continue;

      auto &dp = D[sx][sy][ex][ey];

      // . [...]
      dp = max(dp, D[sx+1][sy][ex][ey]);
      dp = max(dp, D[sx][sy+1][ex][ey]);

      if (is_lower(A[sx][sy])) {
        for (auto [x, y]: holes[A[sx][sy]-'a']) {
          if (x < sx || x > ex || y < sy || y > ey) continue;

          if (x == ex && y == ey) {
            if ((ex-sx) + (ey-sy) == 1) { // (aA)
              dp = 1;
            } else { // (a...A)
              dp = max(dp, D[sx+1][sy][ex-1][ey] + 1);
              dp = max(dp, D[sx+1][sy][ex][ey-1] + 1);
              dp = max(dp, D[sx][sy+1][ex-1][ey] + 1);
              dp = max(dp, D[sx][sy+1][ex][ey-1] + 1);
            }

          } else { // (a...A) [...]
            dp = max(dp, D[sx][sy][x][y] + D[x+1][y][ex][ey]);
            dp = max(dp, D[sx][sy][x][y] + D[x][y+1][ex][ey]);
          }
        }
      }

      // cout << "dp[" << sx << "][" << sy << "][" << ex << "][" << ey << "] = ";
      // cout << (dp >= 0 ? dp : -1) << endl;
    }
  }

  int ans = D[1][1][H][W];
  cout << (ans >= 0 ? ans : -1) << endl;
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
