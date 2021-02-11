#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;
lld N, D, A[MN], E[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> D;
  for (int i=0; i<N; i++) cin >> A[i];

  priority_queue<pll> pq;
  for (int i=0; i<N; i++) {
    while (!pq.empty() && pq.top().second < i-D) pq.pop();

    E[i] = A[i];
    if (!pq.empty()) E[i] = max(E[i], pq.top().first + A[i]);
    
    pq.push({E[i], i});
  }

  cout << *max_element(E, E+N) << endl;

  ////////////////////////////////
  return 0;
}
