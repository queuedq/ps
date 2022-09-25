#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
lld N, wdeg[MN], ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      lld c; cin >> c;
      wdeg[i] += c;
      ans += c;
    }
  }
  ans /= 2;

  sort(wdeg, wdeg+N);
  for (int i=0; i<N/2; i++) ans -= wdeg[i];
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
