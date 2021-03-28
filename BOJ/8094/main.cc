#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int n, w, cnt[201];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> w >> n;
  for (int i=0; i<n; i++) {
    int t; cin >> t;
    cnt[t]++;
  }

  int ans = 0;
  for (int i=1; i<=w; i++) {
    while (cnt[i] > 0) {
      cnt[i]--;
      ans++;
      int j = w-i;
      while (j > 0 && cnt[j] == 0) j--;
      if (j > 0) cnt[j]--;
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
