#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 17;
const int INF = 1e9;
int N, W[MN][MN], D[1<<MN][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) cin >> W[i][j];
  }

  for (int vst = 0; vst < 1<<N; vst++) fill(D[vst], D[vst]+N, INF);
  D[1][0] = 0;

  for (int vst = 0; vst < 1<<N; vst++) {
    for (int i=0; i<N; i++) {
      if ((vst>>i & 1) == 0) continue;
      for (int j=0; j<N; j++) {
        if (W[j][i] == 0 || (vst>>j & 1) == 0) continue;
        D[vst][i] = min(D[vst][i], D[vst - (1<<i)][j] + W[j][i]);
      }
    }
  }

  int ans = INF;
  for (int i=0; i<N; i++) {
    if (D[(1<<N) - 1][i] == INF || W[i][0] == 0) continue;
    ans = min(ans, D[(1<<N) - 1][i] + W[i][0]);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
