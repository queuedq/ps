#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

struct Circle {
  lld l, r;
  bool operator<(const Circle &c) const {
    return l == c.l ? r > c.r : l < c.l;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int N; cin >> N;
  vector<Circle> A;
  for (int i=0; i<N; i++) {
    lld x, r; cin >> x >> r;
    A.push_back({x-r, x+r});
  }

  sort(A.begin(), A.end());

  stack<Circle> S;
  stack<lld> T;
  lld ans = N+1;
  for (int i=0; i<N; i++) {
    while (!S.empty() && S.top().r <= A[i].l) {
      Circle c = S.top(); S.pop();
      lld s = T.top(); T.pop();
      if (c.r - c.l == s) ans++;
    }
    if (!T.empty()) T.top() += A[i].r - A[i].l;
    S.push(A[i]); T.push(0);
  }

  while (!S.empty()) {
    Circle c = S.top(); S.pop();
    lld s = T.top(); T.pop();
    if (c.r - c.l == s) ans++;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
