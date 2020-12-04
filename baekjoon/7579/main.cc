#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 105, MAXC = 10005;
int N, M, m[MAXN], c[MAXN], D[MAXN][MAXC];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) cin >> m[i];
  for (int i=0; i<N; i++) cin >> c[i];

  D[0][c[0]] = m[0];
  for (int i=1; i<N; i++) {
    for (int j=0; j<MAXC; j++) {
      D[i][j] = D[i-1][j];
      if (j - c[i] >= 0) D[i][j] = max(D[i][j], D[i-1][j-c[i]] + m[i]);
    }
  }

  int ans;
  for (int j=0; j<MAXC; j++) {
    if (D[N-1][j] >= M) {
      ans = j;
      break;
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
