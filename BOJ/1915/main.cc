#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
int N, M, D[MAXN][MAXN];
string A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }

  int ans = 0;

  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      if (A[i][j] == '0') D[i][j] = 0;
      else if (i == 0 || j == 0) D[i][j] = 1;
      else {
        int a = D[i-1][j];
        int b = D[i][j-1];
        if (a == b && A[i-a][j-a] == '0') D[i][j] = a;
        else D[i][j] = min(a, b) + 1;
      }
      ans = max(ans, D[i][j]);
    }
  }

  cout << ans * ans << endl;

  ////////////////////////////////
  return 0;
}
