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
int N, K, C[MN];
pll A[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N; i++) {
    lld m, v; cin >> m >> v;
    A[i] = {m, v};
  }
  for (int i=0; i<K; i++) cin >> C[i];

  sort(A, A+N);
  sort(C, C+K);

  priority_queue<lld> pq;
  lld ans = 0;
  for (int j=0, i=0; j<K; j++) {
    while (i<N && A[i].first<=C[j]) { pq.push(A[i].second); i++; }
    if (!pq.empty()) { ans += pq.top(); pq.pop(); }
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
