#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N;

lld dist_interval(lld s1, lld e1, lld s2, lld e2) {
  if (e1 < s2) return s2 - e1;
  if (e2 < s1) return s1 - e2;
  return 0;
}

struct Rect {
  lld x1, y1, x2, y2;

  lld dist(Rect R) {
    lld xd = dist_interval(x1, x2, R.x1, R.x2);
    lld yd = dist_interval(y1, y2, R.y1, R.y2);
    return max(xd, yd);
  }

  Rect expand(lld d) {
    return {x1-d, y1-d, x2+d, y2+d};
  }

  Rect intersection(Rect R) {
    return {max(x1, R.x1), max(y1, R.y1), min(x2, R.x2), min(y2, R.y2)};
  }
};

Rect R[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    lld x, y, P; cin >> x >> y >> P;
    R[i] = {x-P, y-P, x+P, y+P};
  }

  Rect X = R[0];
  lld sum = 0;
  for (int i=1; i<N; i++) {
    lld d = X.dist(R[i]);
    X = X.expand(d).intersection(R[i]);
    sum += d;
  }

  cout << sum << endl;

  ////////////////////////////////
  return 0;
}
