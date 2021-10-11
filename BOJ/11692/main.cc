#include <bits/stdc++.h>
using namespace std;
using lld = long long;

int main() {
  lld m; cin >> m;
  lld ans = m;
  for (lld s=1; s*s<=m; s+=2) ans -= floor(log2(m/s/s)) + 1;
  cout << ans << endl;
  return 0;
}
