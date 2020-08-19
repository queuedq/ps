#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 2e9+5;
const int MAXN = 10'005;
int N, D[MAXN][MAXN];
pii A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i].first;
  for (int i=1; i<=N; i++) cin >> A[i].second;
  sort(A+1, A+N+1);

  for (int i=1; i<=N; i++) fill(D[i], D[i]+N, INF);
  D[1][0] = A[1].first;

  for (int i=1; i<N; i++) {
    for (int j=0; j<i; j++) {
      if (D[i][j]+A[i+1].second < A[i+1].first) {
        D[i+1][j] = min(D[i+1][j], A[i+1].first);
        D[i+1][j+1] = min(D[i+1][j+1], D[i][j]+A[i+1].second);
      } else if (D[i][j] <= A[i+1].first) {
        D[i+1][j] = min(D[i+1][j], D[i][j]+A[i+1].second);
      } else {
        D[i+1][j+1] = min(D[i+1][j+1], D[i][j]+A[i+1].second);
      }
    }
    D[i+1][i] = min(D[i+1][i], A[i+1].first);
  }

  int ans = 0;
  for (; ans<N; ans++) {
    if (D[N][ans] < INF) break;
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
