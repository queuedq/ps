#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 100'005;
int N, M, D[MN][20], lg[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) cin >> D[i][0];

  for (int k=1; k<20; k++) {
    for (int i=1; i + (1<<k) - 1 <= N; i++) {
      D[i][k] = min(D[i][k-1], D[i + (1 << k-1)][k-1]);
    }
  }

  lg[1] = 0;
  for (int i=2; i<=N; i++) lg[i] = lg[i/2] + 1;

  for (int i=0; i<M; i++) {
    int a, b; cin >> a >> b;
    int k = lg[b - a + 1];
    cout << min(D[a][k], D[b - (1 << k) + 1][k]) << endl;
  }

  ////////////////////////////////
  return 0;
}
