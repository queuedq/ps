#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
const int dx[5] = {0, 0, 1, 0, -1};
const int dy[5] = {0, 1, 0, -1, 0};
int N, M, K;

struct Cell {
  int x, y, v;
  bool operator<(const Cell &C) const { return v < C.v; }
};
vector<Cell> A;
int vst[MN][MN], ans;

bool oob(int x, int y) { return x < 0 || x >= N || y < 0 || y >= M; }

void solve(int cnt, int s, int sum) {
  ans = max(ans, sum);
  if (cnt == K) return;

  for (int i=s; i<sz(A); i++) {
    auto [x, y, v] = A[i];
    if (vst[x][y]) continue;

    for (int d=0; d<5; d++) {
      int xx = x+dx[d], yy = y+dy[d];
      if (!oob(xx, yy)) vst[xx][yy]++;
    }

    solve(cnt+1, i+1, sum+v);

    for (int d=0; d<5; d++) {
      int xx = x+dx[d], yy = y+dy[d];
      if (!oob(xx, yy)) vst[xx][yy]--;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      int v; cin >> v;
      A.push_back({i, j, v});
    }
  }

  sort(A.rbegin(), A.rend());
  A.resize(min(5*(K-1)+1, sz(A))); // pigeonhole principle

  solve(0, 0, 0);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
