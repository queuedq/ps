#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
lld N, A[MN];

struct Node {
  lld i, cnt;
  lld delta() const { return A[i] * (cnt*2 + 1); }
  bool operator <(const Node &n) const { return delta() > n.delta(); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  sort(A, A+N);
  
  priority_queue<Node> pq;
  pq.push({0, 0});
  for (int i=1; i<N; i++) {
    auto [j, cnt] = pq.top(); pq.pop();
    pq.push({j, cnt+1});
    pq.push({i, 1});
  }

  lld ans = 0;
  while (!pq.empty()) {
    auto [i, cnt] = pq.top(); pq.pop();
    ans += A[i] * cnt*cnt;
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
