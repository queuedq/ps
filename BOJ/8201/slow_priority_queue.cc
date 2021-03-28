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

  priority_queue<int> mx, rmx;
  priority_queue<int, vector<int>, greater<int>> mn, rmn;

  int j = 0, ans = 0;
  for (int i=0; i<n; i++) {
    mx.push(A[i]);
    mn.push(A[i]);
    while (!mx.empty() && mx.top() - mn.top() > t) {
      rmx.push(A[j]);
      rmn.push(A[j]);
      while (!rmx.empty() && mx.top() == rmx.top()) {
        mx.pop();
        rmx.pop();
      }
      while (!rmn.empty() && mn.top() == rmn.top()) {
        mn.pop();
        rmn.pop();
      }
      j++;
    }

    ans = max(ans, i - j + 1);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
