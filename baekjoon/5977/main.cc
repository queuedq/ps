#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;
lld N, K, E[MN], tot, D[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) {
    cin >> E[i];
    tot += E[i];
  }

  deque<pll> dq;
  dq.push_back({0, 0}); // D[0] = 0

  for (int i=1; i<=N+1; i++) {
    while (!dq.empty() && dq.front().second < i-K-1) dq.pop_front();

    D[i] = dq.front().first + E[i];
    
    while (!dq.empty() && dq.back().first >= D[i]) dq.pop_back();
    dq.push_back({D[i], i});
  }

  cout << tot - D[N+1] << endl;

  ////////////////////////////////
  return 0;
}
