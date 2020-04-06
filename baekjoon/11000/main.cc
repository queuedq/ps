#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;
vector<pii> A;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  A.resize(N);
  for (int i=0; i<N; i++) cin >> A[i].first >> A[i].second;
  sort(A.begin(), A.end());

  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i=0; i<N; i++) {
    if (pq.empty() || pq.top() > A[i].first) {
      pq.push(A[i].second);
    } else {
      pq.pop();
      pq.push(A[i].second);
    }
  }

  cout << pq.size() << endl;

  ////////////////////////////////
  return 0;
}
