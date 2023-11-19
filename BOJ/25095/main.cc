#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int _N = 105;
const int _W = 105;
int T, N, W, X[_N][_W], cnt[_W], common[_N][_N], D[_N][_N];

void solve(int test) {
  cin >> N >> W;
  for (int i=1; i<=N; i++) {
    for (int w=1; w<=W; w++) {
      cin >> X[i][w];
    }
  }

  // calc common in range [i, j]
  for (int i=1; i<=N; i++) {
    fill(cnt, cnt+W+1, INT_MAX);

    for (int j=i; j<=N; j++) {
      common[i][j] = 0;
      for (int w=1; w<=W; w++) {
        cnt[w] = min(cnt[w], X[j][w]);
        common[i][j] += cnt[w];
      }
    }
  }

  // interval dp
  for (int i=1; i<=N; i++) D[i][i] = common[i][i];

  for (int l=2; l<=N; l++) {
    for (int i=1, j=l; j<=N; i++, j++) {
      D[i][j] = INT_MAX;
      for (int k=i; k<j; k++) {
        D[i][j] = min(D[i][j], D[i][k] + D[k+1][j] - common[i][j]);
      }
    }
  }

  cout << "Case #" << test << ": " << D[1][N] * 2 << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> T;
  for (int t=1; t<=T; t++) solve(t);

  ////////////////////////////////
  return 0;
}
