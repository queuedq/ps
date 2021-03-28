#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct Point { lld x, y; };
bool operator<(Point a, Point b) { return (pll){a.x, a.y} < (pll){b.x, b.y}; }
bool operator==(Point a, Point b) { return a.x == b.x && a.y == b.y; }
Point operator+(Point a, Point b) { return {a.x + b.x, a.y + b.y}; }
Point operator-(Point a, Point b) { return {a.x - b.x, a.y - b.y}; }
Point operator*(lld a, Point b) { return {a * b.x, a * b.y}; }
lld operator*(Point a, Point b) { return a.x * b.x + a.y * b.y; }
ostream& operator<<(ostream& os, Point a) { os << "{" << a.x << "," << a.y << "}"; return os; }

lld cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
lld ccw(Point a, Point b, Point c) { return cross(b-a, c-a); }
double length(Point a) { return sqrt(a * a); }
double angle(Point a, Point b) {
  double c = a * b / length(a) / length(b);
  double s = cross(a, b) / length(a) / length(b);
  return atan2(s, c);
}

////////////////////////////////////////////////////////////////
const int MAXN = 10'005;
struct Line {
  Point p, q;
} L[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int S; cin >> S;
  for (int i=0; i<S; i++) {
    cin >> L[i].p.x >> L[i].p.y >> L[i].q.x >> L[i].q.y;
  }

  int T; cin >> T;
  while (T--) {
    Point a, b;
    cin >> a.x >> a.y >> b.x >> b.y;

    bool same = true;
    for (int i=0; i<S; i++) {
      bool ar = ccw(L[i].p, L[i].q, a) > 0;
      bool br = ccw(L[i].p, L[i].q, b) > 0;
      same ^= ar ^ br;
    }

    if (same) cout << "same" << endl;
    else cout << "different" << endl;
  }

  ////////////////////////////////
  return 0;
}
