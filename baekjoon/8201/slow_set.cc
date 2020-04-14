#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 3e6+5;
int t, n, A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> t >> n;
  for (int i=0; i<n; i++) cin >> A[i];

  multiset<int> S;
  int j = 0, ans = 0;
  for (int i=0; i<n; i++) {
    S.insert(A[i]);
    while (!S.empty() && *S.rbegin() - *S.begin() > t) {
      S.erase(S.lower_bound(A[j++]));
    }

    for (auto s: S) cout << s << " "; cout << endl;
    ans = max(ans, (int)S.size());
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
