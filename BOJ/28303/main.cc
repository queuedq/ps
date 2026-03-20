#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505050;
int N, K, A[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N; i++) cin >> A[i];

  int ans = -2e9;
  int mn = 2e9;
  for (int i=0; i<N; i++) {
    ans = max(ans, A[i] - K*i - mn);
    mn = min(mn, A[i] - K*i);
  }

  mn = 2e9;
  for (int i=N-1; i>=0; i--) {
    ans = max(ans, A[i] + K*i - mn);
    mn = min(mn, A[i] + K*i);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
