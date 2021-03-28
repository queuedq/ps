#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 1e18;
const lld MAXN = 3005;
lld N, M, L;
lld A[MAXN], B[MAXN];
lld D[MAXN][MAXN][2]; // 0: anchored left

lld dist(int i, int j) { return (A[i]-B[j])*(A[i]-B[j]) + L*L; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> L;
  for (int i=0; i<N; i++) cin >> A[i];
  for (int i=0; i<M; i++) cin >> B[i];

  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      if (i == 0 && j == 0) {
        continue; // D[...] = 0;
      } else if (i == 0) {
        D[i][j][0] = D[i][j-1][0] + dist(i, j-1) * (N+M-1);
        D[i][j][1] = INF;
        continue;
      } else if (j == 0) {
        D[i][j][1] = D[i-1][j][1] + dist(i-1, j) * (N+M-1);
        D[i][j][0] = INF;
        continue;
      }

      D[i][j][0] = min({
        D[i][j-1][0] + dist(i, j-1) * (N+M-1),
        D[i][j-1][1] + dist(i, j-1) * (i+j) * (N+M-i-j),
        INF
      });
      D[i][j][1] = min({
        D[i-1][j][1] + dist(i-1, j) * (N+M-1),
        D[i-1][j][0] + dist(i-1, j) * (i+j) * (N+M-i-j),
        INF
      });
    }
  }

  lld ans = min(D[N-1][M-1][0], D[N-1][M-1][1]) + dist(N-1, M-1) * (N+M-1);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
