#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXW = 10005;
int D[MAXW];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int N, M; cin >> N >> M;
  for (int i=0; i<N; i++) {
    int V, C, K; cin >> V >> C >> K;
    for (int j=1; j<K; j*=2) {
      int w = V*j, c = C*j;
      for (int i=M; i>=0; i--) {
        if (i-w < 0) continue;
        D[i] = max(D[i], D[i-w] + c);
      }
      K -= j;
    }

    int w = V*K, c = C*K;
    for (int i=M; i>=0; i--) {
      if (i-w < 0) continue;
      D[i] = max(D[i], D[i-w] + c);
    }
  }

  int ans = 0;
  for (int i=0; i<=M; i++) ans = max(ans, D[i]);

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
