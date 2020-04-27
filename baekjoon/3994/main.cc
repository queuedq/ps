#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
lld x, n;
vector<pll> box[20];

lld pow(int e) {
  lld res = 1;
  while (e > 0) {
    res *= 10;
    e--;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> x >> n;
  for (int i=1; i<=n; i++) {
    lld k, q; cin >> k >> q;
    box[k].push_back({pow(k)*q, i});
  }

  vector<lld> ans;
  lld left = x, pow = 1;
  priority_queue<pll> pq;
  for (int k=0; k<=18; k++) {
    for (auto w: box[k]) pq.push(w);
    lld thres = k == 18 ? 0 : x - x%(pow*10);
    while (left > thres) {
      if (pq.empty()) {
        cout << -1 << endl;
        return 0;
      }
      auto [w, i] = pq.top(); pq.pop();
      left -= w;
      ans.push_back(i);
    }
    pow *= 10;
  }

  cout << ans.size() << endl;
  for (auto a: ans) cout << a << " ";
  cout << endl;

  ////////////////////////////////
  return 0;
}
