#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 5005;
int N, M, S[MN][MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int a, b, x; cin >> a >> b >> x;
    S[a][b]++;
    S[a][b+1]--;
    S[a+x+1][b]--;
    S[a+x+1][b+x+2]++;
    S[a+x+2][b+1]++;
    S[a+x+2][b+x+2]--;
  }

  // horizontal
  for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
    S[i][j] += S[i][j-1];
  }
  // vertical
  for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
    S[i][j] += S[i-1][j];
  }
  // diagonal
  for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
    S[i][j] += S[i-1][j-1];
  }

  int ans = 0;
  for (int i=1; i<=N; i++) for (int j=1; j<=i; j++) {
    if (S[i][j] > 0) ans++;
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
