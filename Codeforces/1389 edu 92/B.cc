#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;

int n, k, z;
int A[MAXN], D[MAXN][6];

void calc() {
  cin >> n >> k >> z;
  for (int i=1; i<=n; i++) cin >> A[i];
  for (int i=0; i<=n; i++) fill(D[i], D[i]+6, -1e9);

  D[0][0] = A[1];
  for (int i=1; i<=k; i++) {
    for (int j=0; j<=z; j++) {
      int dest = i-j*2+1;
      if (dest <= 0) continue;
      D[i][j] = D[i-1][j]+A[dest];
      if (i-2 >= 0 && j-1 >= 0 && dest < n) {
        D[i][j] = max(D[i][j], D[i-2][j-1]+A[dest+1]+A[dest]);
      }
    }
  }

  int ans = 0;
  for (int i=0; i<=z; i++) {
    ans = max(ans, D[k][i]);
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int t; cin >> t;
  while (t--) {
    calc();
  }

  ////////////////////////////////
  return 0;
}
