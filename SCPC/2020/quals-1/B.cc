#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 3005;
int N, K, X[MAXN], Y[MAXN], xp[MAXN], yp[MAXN];
bool win[MAXN][MAXN];
int lose[MAXN][MAXN][2];

void solve(int test) {
  cin >> N >> K;
  for (int i=1; i<=N; i++) cin >> X[i];
  for (int i=1; i<=N; i++) cin >> Y[i];

  int j = 0, sum = 0;
  for (int i=1; i<=N; i++) {
    sum += X[i];
    while (sum > K) sum -= X[++j];
    xp[i] = j;
  }

  j = 0, sum = 0;
  for (int i=1; i<=N; i++) {
    sum += Y[i];
    while (sum > K) sum -= Y[++j];
    yp[i] = j;
  }

  win[0][0] = true;
  lose[0][0][0] = lose[0][0][1] = 0;

  for (int i=1; i<=N; i++) {
    lose[i][0][0] = lose[i-1][0][0] + !win[i-1][0];
    for (int k=xp[i-1]; k<xp[i]; k++) lose[i][0][0] -= !win[k][0];
    win[i][0] = lose[i][0][0] > 0;

    lose[0][i][1] = lose[0][i-1][1] + !win[0][i-1];
    for (int k=yp[i-1]; k<yp[i]; k++) lose[0][i][1] -= !win[0][k];
    win[0][i] = lose[0][i][1] > 0;
  }

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      lose[i][j][0] = lose[i-1][j][0] + !win[i-1][j];
      for (int k=xp[i-1]; k<xp[i]; k++) lose[i][j][0] -= !win[k][j];

      lose[i][j][1] = lose[i][j-1][1] + !win[i][j-1];
      for (int k=yp[j-1]; k<yp[j]; k++) lose[i][j][1] -= !win[i][k];

      win[i][j] = lose[i][j][0] > 0 || lose[i][j][1] > 0;
    }
  }

  int ans = 0;
  for (int i=0; i<=N; i++) {
    for (int j=0; j<=N; j++) {
      ans += win[i][j];
    }
  }

  cout << "Case #" << test << endl;
  cout << ans << " " << (N+1)*(N+1) - ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) solve(t);

  ////////////////////////////////
  return 0;
}
