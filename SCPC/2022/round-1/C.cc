#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N;
map<lld, vector<lld>> X, Y;

lld solve() {
  cin >> N;
  for (int i=0; i<N; i++) {
    lld x, y; cin >> x >> y;
    X[x].push_back(y);
    Y[y].push_back(x);
  }
  
  lld ex = -1, ey = -1;
  for (auto &[x, ys]: X) {
    sort(all(ys));
    if (ys.size() % 2) ex = x;
  }
  for (auto &[y, xs]: Y) {
    sort(all(xs));
    if (xs.size() % 2) ey = y;
  }

  lld ans = 0;
  for (auto &[x, ys]: X) {
    bool b = 1;
    if (x == ex && ys[0] == ey) b = 0;
    
    for (int j=1; j<ys.size(); j++) {
      if (b) ans += ys[j] - ys[j-1];
      if (!(x == ex && ys[j] == ey)) b = !b;
    }
  }

  for (auto &[y, xs]: Y) {
    bool b = 1;
    if (xs[0] == ex && y == ey) b = 0;
    
    for (int j=1; j<xs.size(); j++) {
      if (b) ans += xs[j] - xs[j-1];
      if (!(xs[j] == ex && y == ey)) b = !b;
    }
  }

  return ans;
}

void reset() {
  X.clear();
  Y.clear();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    lld ans = solve();
    reset();
    cout << "Case #" << t << endl;
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
