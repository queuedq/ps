#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
lld N, T, P, K[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> T >> P;
  for (int i=0; i<N; i++) cin >> K[i];

  priority_queue<lld> pq;

  int ans = 0;
  lld sum = 0;
  for (int i=0; i<N; i++) {
    sum += K[i];
    pq.push(K[i]);
    while (!pq.empty() && sum > T - P*i) {
      sum -= pq.top();
      pq.pop();
    }
    ans = max(ans, (int)pq.size());
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
