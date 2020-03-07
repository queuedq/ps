#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int n, w, cnt[205];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> w >> n;
  for (int i=0; i<n; i++) {
    int t; cin >> t;
    cnt[t]++;
  }

  int ans=0, j=0;
  while (cnt[j] == 0) j++;
  for (int i=w; i>=1; i--) {
    while (cnt[i] > 0) {
      cnt[i]--;
      ans++;
      if (i+j <= w) cnt[j]--;
      while (j <= w && cnt[j] == 0) j++;
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
