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
lld N, o[MN], d[MN], S[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> o[i];
  for (int i=1; i<=N; i++) cin >> d[i];
  
  lld mn = 0;
  for (int i=1; i<=N; i++) {
    S[i] = S[i-1] + o[i]-d[i];
    mn = min(mn, S[i]);
  }

  int ans = 0;
  for (int i=1; i<=N; i++) ans += S[i] == mn;
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
