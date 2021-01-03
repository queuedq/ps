#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
struct Point {
  lld x, y;

  bool operator ==(Point a) const { return x == a.x && y == a.y; }
  bool operator !=(Point a) const { return !(*this == a); }
  bool operator <(Point a) const { return pair(x, y) < pair(a.x, a.y); }
  bool operator <=(Point a) const { return pair(x, y) <= pair(a.x, a.y); }
  bool operator >(Point a) const { return pair(x, y) > pair(a.x, a.y); }
  bool operator >=(Point a) const { return pair(x, y) >= pair(a.x, a.y); }
  Point operator +(Point a) const { return {x+a.x, y+a.y}; }
  Point operator -(Point a) const { return {x-a.x, y-a.y}; }
  Point operator *(lld c) const { return {x*c, y*c}; }
  Point operator /(lld c) const { return {x/c, y/c}; }
  lld operator *(Point a) const { return x*a.x + y*a.y; }
};

lld cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }
lld ccw(Point a, Point b, Point c) {
  lld o = cross(b-a, c-a);
  if (o == 0) return 0;
  return o > 0 ? 1 : -1;
}

struct Line {
  Point p, q;

  bool on_segment(Point r) {
    return ccw(p, r, q) == 0 && min(p, q) <= r && r <= max(p, q);
  }
};

bool intersect(Line l, Line m) {
  Point a = l.p, b = l.q, c = m.p, d = m.q;
  if (l.on_segment(c) || l.on_segment(d)) return true;
  if (m.on_segment(a) || m.on_segment(b)) return true;
  return ccw(a, b, c) != ccw(a, b, d) && ccw(c, d, a) != ccw(c, d, b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  Line l, m;
  cin >> l.p.x >> l.p.y >> l.q.x >> l.q.y;
  cin >> m.p.x >> m.p.y >> m.q.x >> m.q.y;
  cout << intersect(l, m) << endl;

  ////////////////////////////////
  return 0;
}
