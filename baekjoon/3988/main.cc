#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
int N, K, A[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N; i++) cin >> A[i];
  sort(A, A+N);

  priority_queue<pii, vector<pii>, greater<pii>> pq;

  for (int i=1; i<N-K; i++) pq.push({A[i]-A[i-1], i});
  int ans = A[N-K-1] - A[0] + pq.top().first;

  for (int i=N-K; i<N; i++) {
    pq.push({A[i]-A[i-1], i});
    while (!pq.empty() && pq.top().second < i-(N-K-1)) pq.pop();
    ans = min(ans, A[i] - A[i-(N-K-1)] + pq.top().first);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
