#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int MN = 21;
int N, L, A[MN][MN], D[MN][MN][MN][MN][MN];

bool oob(int x) { return x<0 | x>=N; }

int dp(int l, int x1, int y1, int x2, int y2) {
  if (oob(x1)|oob(y1)|oob(x2)|oob(y2)) return 0;
  if (A[x1][y1] != A[x2][y2]) return 0;
  int &res = D[l][x1][y1][x2][y2];
  if (res != -1) return res;
  if (l == 1) return res = x1 == x2 && y1 == y2;
  if (l == 2) {
    for (int d=0; d<8; d++) {
      if (x1+dx[d] == x2 && y1+dy[d] == y2) return res = 1;
    }
    return res = 0;
  }
  res = 0;
  for (int d=0; d<8; d++) {
    for (int e=0; e<8; e++) {
      res += dp(l-2, x1+dx[d], y1+dy[d], x2+dx[e], y2+dy[e]);
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> L;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) cin >> A[i][j];
  }

  memset(D, -1, sizeof(D));
  int ans = 0;

  for (int x1=0; x1<N; x1++)
  for (int y1=0; y1<N; y1++)
  for (int x2=0; x2<N; x2++)
  for (int y2=0; y2<N; y2++) {
    ans += dp(L, x1, y1, x2, y2);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}

