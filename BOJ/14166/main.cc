#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
lld N, N1, K, init, ans;
vector<lld> P[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) {
    int M; cin >> M;
    P[i].resize(M);
    for (int j=0; j<M; j++) cin >> P[i][j];
    sort(all(P[i]));
    init += P[i][0];
    for (int j=M-1; j>=0; j--) P[i][j] -= P[i][0];

    if (M == 1) { N--; i--; }
  }
  sort(P+1, P+N+1);

  priority_queue<pair<lld, pll>, vector<pair<lld, pll>>, greater<pair<lld, pll>>> pq;
  pq.push({init, {0, 0}});

  for (int i=0; i<K; i++) {
    auto [cost, pos] = pq.top(); pq.pop();
    auto [j, k] = pos;
    ans += cost;

    if (k+1 < P[j].size()) pq.push({cost - P[j][k] + P[j][k+1], {j, k+1}});
    if (j+1 <= N) {
      pq.push({cost + P[j+1][1], {j+1, 1}});
      if (k == 1) pq.push({cost - P[j][1] + P[j+1][1], {j+1, 1}});
    }
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
