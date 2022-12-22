#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 10101;
const int INF = 1e9;
int N, A[MN], D[2][MN];
// D[i][j]: left i cells, take j (include last), min cost

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N-1; i++) cin >> A[i];

  for (int i=1; i<=N; i++) {
    D[i&1][0] = INF;
    for (int j=1; j<=i; j++) {
      D[i&1][j] = min(D[~i&1][j-1], D[~i&1][i-j] + A[i-1]);
    }
  }
  cout << D[N&1][N/2] << endl;

  ////////////////////////////////
  return 0;
}
