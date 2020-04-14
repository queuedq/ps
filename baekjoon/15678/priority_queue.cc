#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAX_N = 1e5+5;
lld N, D, A[MAX_N], score[MAX_N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> D;
  for (int i=0; i<N; i++) cin >> A[i];

  lld ans = LLONG_MIN;
  priority_queue<pll> pq;
  for (int i=0; i<N; i++) {
    while (!pq.empty() && pq.top().second < i-D) pq.pop();
    if (pq.empty()) score[i] = A[i];
    else score[i] = max(pq.top().first, 0LL) + A[i];
    pq.push({score[i], i});
    ans = max(ans, score[i]);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
