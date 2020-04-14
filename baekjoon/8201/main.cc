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

  deque<pii> mn, mx;

  int j = 0, ans = 0;
  for (int i=0; i<n; i++) {
    while (!mn.empty() && mn.back().first >= A[i]) mn.pop_back();
    mn.push_back({A[i], i});

    while (!mx.empty() && mx.back().first <= A[i]) mx.pop_back();
    mx.push_back({A[i], i});

    while (!mn.empty() && mx.front().first - mn.front().first > t) {
      if (mn.front().second <= j) mn.pop_front();
      if (mx.front().second <= j) mx.pop_front();
      j++;
    }

    ans = max(ans, i - j + 1);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
