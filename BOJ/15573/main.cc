#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int MN = 1010;
int N, M, K, A[MN][MN], vst[MN][MN];

bool oob(int x, int y) {
  return x < 0 || x > N+1 || y < 0 || y > M+2;
}

void dfs(int x, int y, int D) {
  if (oob(x, y) || A[x][y] > D || vst[x][y]) return;
  vst[x][y] = 1;

  for (int d=0; d<4; d++) {
    dfs(x+dx[d], y+dy[d], D);
  }
}

bool check(int D) {
  for (int i=0; i<N+1; i++) for (int j=0; j<M+2; j++) vst[i][j] = 0;
  dfs(0, 0, D);
  int cnt = 0;
  for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) cnt += vst[i][j];
  return cnt >= K;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) cin >> A[i][j];

  int l=0, r=1e6;
  while (l+1 < r) {
    int m = (l+r)/2;
    if (check(m)) r = m;
    else l = m;
  }
  cout << r << endl;

  ////////////////////////////////
  return 0;
}
