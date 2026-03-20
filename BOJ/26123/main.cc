#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
lld N, D, A[MN], ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> D;
  lld mx = 0;
  for (int i=0; i<N; i++) { cin >> A[i]; mx = max(mx, A[i]); }
  lld H = max(mx-D, 0LL);

  for (int i=0; i<N; i++) ans += max(A[i]-H, 0LL);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
