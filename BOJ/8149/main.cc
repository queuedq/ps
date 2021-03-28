#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
lld n, m, W[MAXN], M[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n >> m;
  for (int i=0; i<n; i++) cin >> W[i];
  for (int i=0; i<m; i++) cin >> M[i];

  sort(M, M+m);

  lld tot = 0;
  for (int i=0; i<n; i++) tot += W[i]/M[0]*M[0];

  lld ans = 0;
  for (int i=0; i<m; i++) {
    if (i == 0 || M[i] != M[i-1]) {
      lld newtot = 0;
      for (int j=0; j<n; j++) newtot += W[j]/M[i]*M[i];
      tot = min(tot, newtot);
    }
    if (tot >= M[i]) {
      tot -= M[i];
      ans++;
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
