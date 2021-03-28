#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
int N, W, x[MAXN], y[MAXN];
int D[MAXN][MAXN], E[MAXN][MAXN];

int dist(int i, int j) {
  return abs(x[i]-x[j]) + abs(y[i]-y[j]);
}

int dp(int i, int j) {
  if (i == W+1 || j == W+1) return 0;
  if (D[i][j] > 0) return D[i][j];

  int nxt = max(i, j) + 1;
  int a = dist(i, nxt) + dp(nxt, j);
  int b = dist(j, nxt) + dp(i, nxt);
  D[i][j] = min(a, b);
  E[i][j] = a<b ? 1 : 2;

  return D[i][j];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> W;
  x[0] = y[0] = 1;
  x[1] = y[1] = N;
  for (int i=2; i<W+2; i++) cin >> x[i] >> y[i];

  cout << dp(0, 1) << endl;

  int a=0, b=1;
  for (int i=2; i<W+2; i++) {
    cout << E[a][b] << endl;
    if (E[a][b] == 1) a = i;
    else b = i;
  }

  ////////////////////////////////
  return 0;
}
