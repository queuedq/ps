#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
lld N, K, A[MN], st;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) cin >> A[i];
  sort(A+1, A+N+1);

  for (int i=1; i<=N; i++) {
    if (A[i] < 0) {
      st += A[i];
      A[i] = -A[i];
    }
  }
  sort(A+1, A+N+1);

  priority_queue<pll, vector<pll>, greater<pll>> pq;
  pq.push({st, 0});
  bool skip = 1; // skip empty set
  
  for (int k=0; k<K; k++) {
    auto [sum, i] = pq.top(); pq.pop();
    if (sum == 0 && skip) { skip = 0; k--; }
    else cout << sum << endl;
    
    if (i < N) {
      pq.push({sum + A[i+1], i+1});
      if (i > 0) pq.push({sum - A[i] + A[i+1], i+1});
    }
  }

  ////////////////////////////////
  return 0;
}
