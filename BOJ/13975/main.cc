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

  int T; cin >> T;
  while (T--) {
    cin >> N;
    priority_queue<lld, vector<lld>, greater<lld>> pq;
    for (int i=0; i<N; i++) {
      lld x; cin >> x;
      pq.push(x);
    }

    lld ans = 0;
    while (pq.size() > 1) {
      lld a = pq.top(); pq.pop();
      lld b = pq.top(); pq.pop();
      ans += a+b;
      pq.push(a+b);
    }

    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
