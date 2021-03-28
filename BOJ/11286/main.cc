#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  int N; cin >> N;
  while (N--) {
    int q; cin >> q;
    if (q == 0) {
      if (pq.empty()) {
        cout << "0" << endl;
      } else {
        pii val = pq.top(); pq.pop();
        cout << val.second << endl;
      }
    } else {
      pq.push({abs(q), q});
    }
  }

  ////////////////////////////////
  return 0;
}
