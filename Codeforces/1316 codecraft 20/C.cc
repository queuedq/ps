#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e6+5;
int n,m,p, a[MAXN], b[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin>>n>>m>>p;
  for (int i=0; i<n; i++) { cin>>a[i]; }
  for (int i=0; i<m; i++) { cin>>b[i]; }

  int ans = 0;
  for (int i=0; i<n; i++) {
    if (a[i]%p) {
      ans += i;
      break;
    }
  }
  for (int i=0; i<m; i++) {
    if (b[i]%p) {
      ans += i;
      break;
    }
  }

  cout<<ans<<endl;

  ////////////////////////////////
  return 0;
}
