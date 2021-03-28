#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i=0; i<N; i++) {
    int x; cin >> x;
    pq.push(x);
  }

  int ans = 0;
  while (pq.size() > 1) {
    int a = pq.top(); pq.pop();
    int b = pq.top(); pq.pop();
    ans += a+b;
    pq.push(a+b);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
