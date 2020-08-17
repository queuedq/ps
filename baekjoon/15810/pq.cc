#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MAXN = 1e6+5;
lld N, M, A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;

  priority_queue<pll, vector<pll>, greater<pll>> pq;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    pq.push({A[i], i});
  }

  lld cnt = 0, time = 0;
  while (cnt < M) {
    auto [t, i] = pq.top(); pq.pop();
    pq.push({t+A[i], i});
    time = t;
    cnt++;
  }

  cout << time << endl;

  ////////////////////////////////
  return 0;
}
