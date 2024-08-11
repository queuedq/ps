#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
const int MW = 101010;
lld N, C, W[MN], P[MN], D[MW];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> C;
  for (int i=1; i<=N; i++) cin >> W[i];
  sort(W+1, W+N+1);
  for (int i=1; i<=N; i++) P[i] = P[i-1] + W[i];

  lld ans = min(P[N], C);
  D[0] = 1;
  for (int i=N; i>=1; i--) {
    // i = min unused index
    // bad packing: sum > C - W[i]
    for (int k=0; k<=C; k++) {
      if (!D[k]) continue;
      lld sum = P[i-1] + k;
      if (sum > C - W[i]) ans = min(ans, sum);
    }
    
    for (int k=C; k>=0; k--) {
      if (k-W[i] >= 0) D[k] |= D[k-W[i]];
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
