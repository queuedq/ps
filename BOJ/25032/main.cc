#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int INF = 1e9;
const int MN = 405;
int N, M, A[MN][MN], vst[MN][MN], cnt[MN][MN];
pii pos[MN][MN];

inline int mod(int x, int m) { return (x%m + m) % m; }

int get_size(int x, int y, int c) {
  int xm = mod(x, N), ym = mod(y, M);
  vst[xm][ym] = 1;
  pos[xm][ym] = pii(x, y);

  int sz = 1;
  for (int d=0; d<4; d++) {
    int x1 = x + dx[d], y1 = y + dy[d];
    int x1m = mod(x1, N), y1m = mod(y1, M);
    if (A[x1m][y1m] != c) continue;
    if (vst[x1m][y1m]) {
      if (pos[x1m][y1m] == pii(x1, y1)) continue;
      else return INF;
    }
    sz += get_size(x1, y1, c);
    if (sz >= INF) return INF;
  }
  return sz;
}

void dfs(int x, int y, int c, int sz) {
  vst[x][y] = 2;
  cnt[x][y] = sz;

  for (int d=0; d<4; d++) {
    int x1 = mod(x + dx[d], N), y1 = mod(y + dy[d], M);
    if (A[x1][y1] != c) continue;
    if (vst[x1][y1] == 2) continue;
    dfs(x1, y1, c, sz);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      char c; cin >> c;
      A[i][j] = c == 'W';
    }
  }

  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      if (vst[i][j]) continue;
      int sz = get_size(i, j, A[i][j]);
      if (sz == INF) sz = -1;
      dfs(i, j, A[i][j], sz);
    }
  }

  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      cout << cnt[i][j] << " \n"[j == M-1];
    }
  }

  ////////////////////////////////
  return 0;
}
