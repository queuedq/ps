#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
using piii = pair<int, pii>;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int MN = 105;
const int INF = 1e8;

int H, W, dst[3][MN][MN];
pii src[3];
char A[MN][MN];

bool oob(int i, int j) {
  return i < 0 || i > H+1 || j < 0 || j > W+1;
}

void solve() {
  // init
  cin >> H >> W;

  src[0] = src[1] = src[2] = {0, 0};
  for (int i=1; i<=H; i++) {
    for (int j=1; j<=W; j++) {
      cin >> A[i][j];
      if (A[i][j] == '$') {
        if (src[0] == pii(0, 0)) src[0] = {i, j};
        else src[1] = {i, j};
      }
    }
  }
  for (int i=1; i<=H+1; i++) A[i][W+1] = 0;
  for (int j=1; j<=W+1; j++) A[H+1][j] = 0;

  for (int t=0; t<3; t++) {
    for (int i=0; i<=H+1; i++) for (int j=0; j<=W+1; j++) dst[t][i][j] = INF;
  }

  // Dijkstra
  for (int t=0; t<3; t++) {
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    pq.push({0, src[t]});
    dst[t][src[t].first][src[t].second] = 0;

    while (!pq.empty()) {
      auto [d, p] = pq.top(); pq.pop();
      auto [i, j] = p;
      if (d > dst[t][i][j]) continue;

      for (int k=0; k<4; k++) {
        int ii = i+dx[k], jj = j+dy[k];
        if (oob(ii, jj)) continue;
        if (A[ii][jj] == '*') continue;
        
        int dd = dst[t][i][j] + (A[ii][jj] == '#');
        if (dd >= dst[t][ii][jj]) continue;
        
        dst[t][ii][jj] = dd;
        pq.push({dd, {ii, jj}});
      }
    }
  }

  // ans
  int ans = INF;

  for (int i=0; i<=H+1; i++) {
    for (int j=0; j<=W+1; j++) {
      int sum = dst[0][i][j] + dst[1][i][j] + dst[2][i][j];
      if (A[i][j] == '#') sum -= 2;
      ans = min(ans, sum);
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
