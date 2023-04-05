#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 100;
int N, A[MN][MN], L[MN][MN], R[MN][MN];

void solve(int t) {
  cin >> N;
  if (N > 64) {
    cout << "Case #" << t << endl;
    cout << 0 << endl;
    return;
  }

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) cin >> A[i][j];
  }

  int ans = 0;
  for (int x=1; x<=N; x++) {
    for (int y=1; y<=N; y++) {
      L[x][y] = R[x][y] = A[x][y];
      ans++;

      for (int i=x+1; i<=N; i++) {
        L[i][y] = min(L[i-1][y], A[i][y]);
        R[i][y] = max(R[i-1][y], A[i][y]);
        if (R[i][y] - L[i][y] + 1 == i-x+1) ans++;
      }

      for (int j=y+1; j<=N; j++) {
        L[x][j] = min(L[x][j-1], A[x][j]);
        R[x][j] = max(R[x][j-1], A[x][j]);
        if (R[x][j] - L[x][j] + 1 == j-y+1) ans++;
      }

      for (int i=x+1; i<=N; i++) {
        for (int j=y+1; j<=N; j++) {
          L[i][j] = min({L[i-1][j], L[i][j-1], A[i][j]});
          R[i][j] = max({R[i-1][j], R[i][j-1], A[i][j]});
          if (R[i][j] - L[i][j] + 1 == (i-x+1) * (j-y+1)) ans++;
        }
      }
    }
  }

  cout << "Case #" << t << endl;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
