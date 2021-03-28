#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2505;
int N, ys[MN], Y[MN], S[MN][MN];
pii P[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    int x, y; cin >> x >> y;
    P[i] = {x, y};
    ys[i] = y;
  }

  sort(P+1, P+N+1);
  sort(ys+1, ys+N+1);

  for (int i=1; i<=N; i++) {
    Y[i] = lower_bound(ys+1, ys+N+1, P[i].second) - ys;
  }

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      S[i][j] = S[i][j-1] + S[i-1][j] - S[i-1][j-1] + (Y[i] == j);
    }
  }

  lld ans = N + 1; // sets of size <= 1
  for (int i=1; i<=N; i++) {
    for (int j=i+1; j<=N; j++) {
      int a = min(Y[i], Y[j]), b = max(Y[i], Y[j]);
      ans += (S[j][a-1] - S[i][a-1] + 1) * (S[j][N] - S[i][N] - S[j][b] + S[i][b] + 1);
    }
  }

  cout << ans << endl;
 
  ////////////////////////////////
  return 0;
}
