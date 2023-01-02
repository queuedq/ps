#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
lld N, M, K, X, A[MN][MN], B[MN][MN];

bool oob(int i, int j) {
  return i <= 0 || i > N || j <= 0 || j > M;
}

int solve(lld D) {
  for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
      B[i][j] = A[i][j];

  queue<pii> Q; // pos to reset to X
  // find all pos with diff > D
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) {
      for (int d=0; d<4; d++) {
        int ii = i+dx[d], jj = j+dy[d];
        if (oob(ii, jj)) continue;
        if (B[i][j] < B[ii][jj] - D) {
          Q.push({i, j});
          break;
        }
      }
    }
  }

  int cnt = 0;

  while (!Q.empty()) {
    auto [i, j] = Q.front(); Q.pop();
    if (B[i][j] == X) continue;
    B[i][j] = X;
    cnt++;

    for (int d=0; d<4; d++) {
      int ii = i+dx[d], jj = j+dy[d];
      if (oob(ii, jj)) continue;
      if (B[ii][jj] < X-D) {
        Q.push({ii, jj});
      }
    }
  }

  return cnt;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> K >> X;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) {
      cin >> A[i][j];
    }
  }

  lld l=-1, r=X;
  while (l+1 < r) {
    lld m = (l+r)/2;
    if (solve(m) <= K) r = m;
    else l = m;
  }

  cout << r << endl;

  ////////////////////////////////
  return 0;
}
