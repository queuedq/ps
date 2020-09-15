#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 250'000;
lld N, K, A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N; i++) cin >> A[i];

  priority_queue<pll> L;
  priority_queue<pll, vector<pll>, greater<pll>> R;

  for (int i=0; i<K; i++) L.push({A[i], i});
  while (L.size() > R.size()+1) { R.push(L.top()); L.pop(); }

  int l = L.size(), r = R.size();
  pll mid = L.top();
  lld ans = mid.first;

  for (int i=K; i<N; i++) {
    // Remove old
    if (pll(A[i-K], i) <= mid) l--;
    else r--;

    // Push new
    if (pll(A[i], i) <= mid) { L.push({A[i], i}); l++; }
    else { R.push({A[i], i}); r++; }

    // Find median
    while (l < r) {
      while (R.top().second <= i-K) R.pop();
      L.push(R.top()); R.pop();
      l++; r--;
    }
    while (l > r+1) {
      while (L.top().second <= i-K) L.pop();
      R.push(L.top()); L.pop();
      r++; l--;
    }

    while (!L.empty() && L.top().second <= i-K) L.pop();
    mid = L.top();
    ans += mid.first;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
