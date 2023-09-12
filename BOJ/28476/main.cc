#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2020;
lld N;

struct Point {
  lld x, y;
  Point operator-(Point P) { return {x-P.x, y-P.y}; }
};
Point P[MN];

lld ccw(Point A, Point B, Point C) {
  return A.x*B.y + B.x*C.y + C.x*A.y - A.y*B.x - B.y*C.x - C.y*A.x;
}

struct Event {
  Point P; int v; // v=0: remove, v=1: add
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> P[i].x >> P[i].y;

  lld sum = 0; // sum = 4 convex + 6 concave
  for (int s=0, t=1; s<N; s++, t=(s+1)%N) {
    vector<Event> E;
    lld left = 0;
    for (int i=0; i<N; i++) {
      if (i == s) continue;
      if (ccw(P[s], P[t], P[i]) >= 0) {
        left++;
        E.push_back({P[i] - P[s], 0}); // remove
      } else {
        E.push_back({P[s] - P[i], 1}); // add
      }
    }

    sort(all(E), [&](Event A, Event B) { return ccw({0, 0}, A.P, B.P) > 0; });

    for (auto [P, v]: E) {
      if (v == 0) {
        left--;
        sum += left * (N-2-left);
      } else {
        sum += left * (N-2-left);
        left++;
      }
    }
  }

  cout << (N*(N-1)*(N-2)*(N-3)/4/3/2/1 * 6 - sum) << endl;

  ////////////////////////////////
  return 0;
}
