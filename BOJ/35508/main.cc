#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, D;
array<int, 3> A[MN];
int pmax[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> D;
  for (int i=1; i<=N; i++) {
    int t, a, b; cin >> t >> a >> b;
    A[i] = {t, a, b};
  }
  sort(A+1, A+N+1);

  pmax[0] = 0;
  for (int i=1; i<=N; i++) pmax[i] = max(pmax[i-1], A[i][2]);

  int ans = 0;
  for (int i=N, j=1; i>=1; i--) {
    while (j <= N && A[i][0] + A[j][0] <= D) j++;
    ans = max({ans, A[i][1] + A[i][2], A[i][1] + pmax[j-1]});
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
