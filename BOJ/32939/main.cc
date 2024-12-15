#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
lld N, A[MN];
deque<pll> up, down;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int i=0; i<=N; i++) {
    if (A[i] < A[i+1]) up.push_back({i, A[i+1] - A[i]});
    else down.push_back({i, A[i] - A[i+1]});
  }

  lld cnt = 0, cost = 0;
  while (sz(up) && sz(down)) {
    // greedy match
    auto [i, a] = up.front();
    auto [j, b] = down.front();
    if (a < b) {
      cnt += a;
      cost += a * (j-i) * (j-i);
      up.pop_front();
      down.front().second -= a;
    } else {
      cnt += b;
      cost += b * (j-i) * (j-i);
      up.front().second -= b;
      down.pop_front();
    }
  }

  cout << cnt << " " << cost << endl;

  ////////////////////////////////
  return 0;
}
