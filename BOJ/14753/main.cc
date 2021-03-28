#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int n, a[10005];
vector<int> b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);

  for (int i = 0; i < n; i++) {
    if (i < 3 || i >= n-3) b.push_back(a[i]);
  }

  int m = b.size();
  int ans = INT_MIN;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < i; j++) {
      ans = max(ans, b[i] * b[j]);
      for (int k = 0; k < j; k++) {
        ans = max(ans, b[i] * b[j] * b[k]);
      }
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
