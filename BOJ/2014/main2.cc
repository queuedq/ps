#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int K, N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> K >> N;
  vector<int> P(K);
  for (int i=0; i<K; i++) cin >> P[i];

  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i=0; i<K; i++) pq.push(P[i]);

  int ans = 0;
  while (N--) {
    ans = pq.top(); pq.pop();
    int maxp = 0;
    for (int i=0; i<K; i++) {
      if (ans % P[i] == 0) maxp = i;
    }
    for (int i=maxp; i<K; i++) {
      lld m = (lld)ans * P[i];
      if (m < INT_MAX) pq.push(m);
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
