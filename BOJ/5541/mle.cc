#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 5050;
int N, M, S[MN][MN], T[MN][MN];
// S[i][j]: +1 to r>=i and c>=j
// T[i][j]: +1 to r-i>=c-j and c>=j

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int a, b, x; cin >> a >> b >> x;
    // 1. make trapezoid
    T[a][b]++;
    T[a+x+1][b+x+1]--;
    // 2. remove bottom rectangle
    S[a+x+1][b]--;
    S[a+x+1][b+x+1]++;
  }

  for (int i=1; i<=N; i++) for (int j=1; j<=i; j++) {
    S[i][j] += S[i][j-1];
    T[i][j] += T[i-1][j-1];
  }
  for (int i=1; i<=N; i++) for (int j=1; j<=i; j++) {
    S[i][j] += S[i-1][j];
    T[i][j] += T[i-1][j];
  }

  int ans = 0;
  for (int i=1; i<=N; i++) for (int j=1; j<=i; j++) {
    if (S[i][j] + T[i][j] > 0) ans++;
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
