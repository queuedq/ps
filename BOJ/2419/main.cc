#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 1e18;
const int MN = 305;
lld N, M, o, x[MN], D[MN][MN][2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) cin >> x[i];
  x[N] = 0;
  sort(x, x+N+1);
  o = find(x, x+N+1, 0) - x;

  lld ans = -INF;

  for (int s=0; s<=N; s++) { // will have s candies
    for (int l=o; l>=0; l--) {
      for (int r=o; r<=N; r++) {
        if (l == o && r == o) continue;

        D[l][r][0] = D[l][r][1] = INF;

        if (l < o) {
          D[l][r][0] = min(
            D[l+1][r][0] + (x[l+1]-x[l]) * (s - (r-l-1)),
            D[l+1][r][1] + (x[r]-x[l]) * (s - (r-l-1))
          );
        }
        if (r > o) {
          D[l][r][1] = min(
            D[l][r-1][1] + (x[r]-x[r-1]) * (s - (r-l-1)),
            D[l][r-1][0] + (x[r]-x[l]) * (s - (r-l-1))
          );
        }
      }
    }

    for (int l=o; l>=0; l--) {
      int r = l+s;
      if (o <= r && r <= N) ans = max(ans, M*s - min(D[l][r][0], D[l][r][1]));
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
