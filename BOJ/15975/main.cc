#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 100'005;
int N;
vector<int> A[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int x, y; cin >> x >> y;
    A[y].push_back(x);
  }

  lld ans = 0;
  for (int i=1; i<=N; i++) {
    int n = A[i].size();
    if (n <= 1) continue;

    sort(A[i].begin(), A[i].end());
    ans += (A[i][1] - A[i][0]) + (A[i][n-1] - A[i][n-2]);
    for (int j=1; j<n-1; j++) {
      ans += min(A[i][j] - A[i][j-1], A[i][j+1] - A[i][j]);
    }
  }
  
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
