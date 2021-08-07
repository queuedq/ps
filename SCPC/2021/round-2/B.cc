#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

lld dist(pll A, pll B) {
  return abs(A.first - B.first) + abs(A.second - B.second);
}

lld dp(lld x, lld y, lld K, vector<pll> &A) {
  vector<pll> B = {
    {x, y+K},
    {x, y+K*2},
    {x+K, y+K*3},
    {x+K*2, y+K*3},
    {x+K*3, y+K*2},
    {x+K*3, y+K},
    {x+K*2, y},
    {x+K, y},
  };

  vector<lld> D(1<<8);
  for (int m=1; m<1<<8; m++) {
    D[m] = LLONG_MAX;
    int cnt = 0;
    for (int i=0; i<8; i++) cnt += (m>>i & 1);
    for (int i=0; i<8; i++) {
      if (m>>i & 1) {
        D[m] = min(D[m], D[m^(1<<i)] + dist(A[cnt-1], B[i]));
      }
    }
  }

  return D[(1<<8) - 1];
}

void solve(int test) {
  int K;
  vector<lld> xs, ys;
  vector<pll> A;

  cin >> K;
  for (int i=0; i<8; i++) {
    lld x, y; cin >> x >> y;
    A.push_back({x, y});
    for (int j=0; j<4; j++) {
      xs.push_back(x - K*j);
      ys.push_back(y - K*j);
    }
  }
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  sort(ys.begin(), ys.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());

  lld ans = LLONG_MAX;
  for (auto x: xs) {
    for (auto y: ys) {
      ans = min(ans, dp(x, y, K, A));
    }
  }

  cout << "Case #" << test << endl;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
