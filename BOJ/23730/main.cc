#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, M, A[MN], ans[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int i=0; i<M; i++) {
    int j; cin >> j;
    ans[j] = A[j];
  }

  for (int i=1; i<=N; i++) {
    if (ans[i]) continue;
    for (int j=1; j<=5; j++) {
      if (j != ans[i-1] && j != ans[i+1] && j != A[i]) {
        ans[i] = j;
        break;
      }
    }
  }

  for (int i=1; i<=N; i++) cout << ans[i] << " ";

  ////////////////////////////////
  return 0;
}
