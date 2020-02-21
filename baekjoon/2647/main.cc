#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAXN = 108;
const int INF = 1e8;
int N;
string P;
// D[l][r][h]: total distance of [l, r) when max height is leq h
int D[MAXN][MAXN][MAXN/2];
int conn[MAXN][MAXN][MAXN/2];

void track(int l, int r, int h, vector<pii> &ans) {
  if (l == r) return;
  if (conn[l][r][h] == -2) {
    ans.push_back({l+1, r});
    track(l+1, r-1, h, ans);
    return;
  }
  track(l, conn[l][r][h], h, ans);
  track(conn[l][r][h], r, h, ans);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> P;
  for (int l = 0; l <= N; l++) {
    for (int r = 0; r <= N; r++) {
      fill(D[l][r], D[l][r] + N/2+1, INF);
      fill(conn[l][r], conn[l][r] + N/2+1, -1);
    }
  }

  for (int d = 2; d <= N; d += 2) {
    for (int l = 0; l <= N-d; l++) {
      int r = l+d;

      if (d == 2 && P[l] != P[l+1]) {
        for (int h = 1; h <= N/2; h++) {
          D[l][r][h] = 3;
          conn[l][r][h] = -2;
        }
        continue;
      }

      for (int h = 1; h <= N/2; h++) {
        for (int m = l+2; m <= r-2; m += 2) {
          if (D[l][m][h] + D[m][r][h] < D[l][r][h]) {
            D[l][r][h] = D[l][m][h] + D[m][r][h];
            conn[l][r][h] = m;
          }
        }
        if (P[l] != P[r-1] && D[l+1][r-1][h-1] + 2*h+d-1 < D[l][r][h]) {
          D[l][r][h] = D[l+1][r-1][h-1] + 2*h+d-1;
          conn[l][r][h] = -2;
        }
        if (h > 1 && D[l][r][h-1] < D[l][r][h]) {
          D[l][r][h] = D[l][r][h-1];
          conn[l][r][h] = conn[l][r][h-1];
        }
      }
    }
  }

  cout << D[0][N][N/2] << endl;

  vector<pii> ans;
  track(0, N, N/2, ans);
  for (auto p: ans) {
    cout << p.first << " " << p.second << endl;
  }

  ////////////////////////////////
  return 0;
}
