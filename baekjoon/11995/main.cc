#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2005;
int n, m, A, B, a[MN], b[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> A >> B >> n >> m;
  for (int i=1; i<=n; i++) cin >> a[i];
  a[n+1] = A;
  sort(a, a+n+2);
  for (int i=1; i<=m; i++) cin >> b[i];
  b[m+1] = B;
  sort(b, b+m+2);
  
  vector<pll> edge;
  for (int i=1; i<=n+1; i++) edge.push_back({a[i] - a[i-1], true});
  for (int i=1; i<=m+1; i++) edge.push_back({b[i] - b[i-1], false});
  sort(edge.begin(), edge.end());

  int v = 0, h = 0;
  lld ans = 0;
  for (auto [w, d]: edge) {
    if (d) {
      if (v == 0 || h == 0) ans += w * m;
      else ans += w * (m-h+1);
      v++;
    } else {
      if (v == 0 || h == 0) ans += w * n;
      else ans += w * (n-v+1);
      h++;
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
