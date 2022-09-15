#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 55;
const int MH = 505;
const int O = MN*MH;
int N, M, A[MN][MN], D[MN][O*2], ans;
unordered_map<int, int> cntX[MN], cntY[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) cin >> A[i][j];
  }

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) {
      int dx = A[i==1 ? N : i-1][j] - A[i][j];
      int dy = A[i][j==1 ? M : j-1] - A[i][j];
      cntX[i][dx]++;
      cntY[j][dy]++;
    }
  }

  for (auto [d, c]: cntX[1]) D[1][O+d] = c;
  for (int i=2; i<=N; i++) {
    int mx = *max_element(D[i-1], D[i-1]+O*2);
    fill(D[i], D[i]+O*2, mx);
    for (int x=-O; x<O; x++) {
      for (auto [d, c]: cntX[i]) {
        if (x-d < -O || x-d >= O) continue;
        D[i][O+x] = max(D[i][O+x], D[i-1][O+x-d] + c);
      }
    }
  }

  ans += D[N][O];
  memset(D, 0, sizeof(D));

  for (auto [d, c]: cntY[1]) D[1][O+d] = c;
  for (int j=2; j<=M; j++) {
    int mx = *max_element(D[j-1], D[j-1]+O*2);
    fill(D[j], D[j]+O*2, mx);
    for (int x=-O; x<O; x++) {
      for (auto [d, c]: cntY[j]) {
        if (x-d < -O || x-d >= O) continue;
        D[j][O+x] = max(D[j][O+x], D[j-1][O+x-d] + c);
      }
    }
  }

  ans += D[M][O];
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
