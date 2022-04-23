#include <bits/stdc++.h>
using namespace std;

int N, K, A[101010];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N; i++) cin >> A[i];

  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i=0; i<N+K; i++) {
    if (i < N) pq.push(A[i]);
    if (i >= K) { cout << pq.top() << ' '; pq.pop(); }
  }

  ////////////////////////////////
  return 0;
}
