#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e7+5;
lld N, A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  N = 1e7;

  priority_queue<lld, vector<lld>, greater<lld>> pq;
  pq.push(1);
  for (int i=1; i<=N; i++) {
    A[i] = pq.top();
    while (!pq.empty() && pq.top() == A[i]) pq.pop();
    pq.push(A[i]*2+1);
    pq.push(A[i]*3+1);
    assert(A[i] > 0);
  }

  int T; cin >> T;
  while (T--) {
    cin >> N;
    cout << A[N] << endl;
  }

  ////////////////////////////////
  return 0;
}
