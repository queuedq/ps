#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int UP = 1, DOWN = 2;
struct Point { int x, y; };

int N, cut, rot;
vector<Point> P;
vector<pair<double, int>> pass; // (x, dir) of line passing through cut

double inter(Point A, Point B, int h) { // with horizontal line
  double dx = B.x - A.x, dy = B.y - A.y;
  return A.x + (h-A.y) / dy * dx;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  if (y1 == y2) cut = y1;
  else cut = x1, rot = true; // rotate ccw to make cut horizontal

  cin >> N;
  for (int i=0; i<N; i++) {
    int x, y; cin >> x >> y;
    if (rot) swap(x, y), x = -x;
    P.push_back({x, y});
  }

  // start from a point not on the cut
  while (P[0].y == cut) rotate(P.begin(), P.begin()+1, P.end());

  // collect pass points
  P.push_back(P[0]);

  for (int i=0; i<N; i++) {
    auto A = P[i], B = P[i+1];

    // enter cut
    if (A.y < cut && cut <= B.y) pass.push_back({inter(A, B, cut), UP});
    if (A.y > cut && cut >= B.y) pass.push_back({inter(A, B, cut), DOWN});

    // exit cut
    if (A.y <= cut && cut < B.y) pass.push_back({inter(A, B, cut), UP});
    if (A.y >= cut && cut > B.y) pass.push_back({inter(A, B, cut), DOWN});
  }

  // edge case: not passing the cut
  if (pass.empty()) { cout << 1 << endl; return 0; }

  // count outer boundaries of regions
  assert(sz(pass) % 2 == 0);
  pass.push_back(pass[0]);
  int cnt = 0;

  for (int i=1; i<sz(pass); i+=2) {
    auto [x1, d1] = pass[i]; // exit
    auto [x2, d2] = pass[i+1]; // enter
    assert(d1 != d2);

    // edge case: x1 == x2 is possible if P meets the cut at a single point
    // so not x2 < x1, but x2 <= x1
    if (d1 == UP && x2 <= x1) cnt++;
    if (d1 == DOWN && x1 <= x2) cnt++;
  }

  cout << cnt << endl;

  ////////////////////////////////
  return 0;
}
