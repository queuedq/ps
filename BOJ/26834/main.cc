#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 1e18;
const int MN = 202020;
const double PI = acos(-1);

struct Point {
  lld x, y;
  double angle;
  Point operator+(Point P) const { return {x+P.x, y+P.y}; }
  Point operator-(Point P) const { return {x-P.x, y-P.y}; }
  bool operator<(Point P) const { return angle < P.angle; }
  lld len() const { return x*x + y*y; }
};

int N;
Point P[MN*2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    lld x, y; cin >> x >> y;
    P[i] = {x, y, atan2(y, x)};
  }
  sort(P, P+N);

  for (int i=0; i<N; i++) {
    P[i+N] = P[i];
    P[i+N].angle += 2*PI;
  }
  P[N*2] = {0, 0, 4*PI};

  Point S = {0, 0};
  int j = 0;
  while (P[j].angle < 0) S = S + P[j++];

  lld mx = S.len();
  for (int i=0; i<N; i++) {
    S = S - P[i];
    mx = max(mx, S.len());
    while (P[j].angle < P[i+1].angle + PI) {
      S = S + P[j++];
      mx = max(mx, S.len());
    }
  }
  cout << mx << endl;

  ////////////////////////////////
  return 0;
}
