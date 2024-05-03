#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
lld N, L[MN], P[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) cin >> L[i];
  for (int i=0; i<N; i++) cin >> P[i];

  lld ans = 0, pr = P[0];
  for (int i=1; i<N; i++) {
    ans += pr * L[i-1];
    pr = min(pr, P[i]);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
