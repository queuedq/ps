#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct Point {
  lld x, y;
  Point(): x(0), y(0) {}
  Point(lld x, lld y): x(x), y(y) {}

  bool operator ==(Point a) const { return x == a.x && y == a.y; }
  bool operator !=(Point a) const { return !(*this == a); }
  bool operator <(Point a) const { return pair(x, y) < pair(a.x, a.y); }
  bool operator <=(Point a) const { return pair(x, y) <= pair(a.x, a.y); }
  Point operator +(Point a) const { return {x+a.x, y+a.y}; }
  Point operator -(Point a) const { return {x-a.x, y-a.y}; }
  Point operator *(lld c) const { return {x*c, y*c}; }
  Point operator /(lld c) const { return {x/c, y/c}; }
  lld operator *(Point a) const { return x*a.x + y*a.y; }
};

lld cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }
lld ccw(Point a, Point b, Point c) {
  lld o = cross(b-a, c-a);
  return (o > 0) - (o < 0);
}

struct Line {
  Point s, e;

  bool contains(Point r) {
    return ccw(s, r, e) == 0 && min(s, e) <= r && r <= max(s, e);
  }

  double get_y(lld x) const {
    if (x == s.x) return s.y;
    return s.y + (double)(e.y-s.y) * (x-s.x)/(e.x-s.x);
  }
};

bool intersect(Line l, Line m) {
  Point a = l.s, b = l.e, c = m.s, d = m.e;
  if (l.contains(c) || l.contains(d)) return true;
  if (m.contains(a) || m.contains(b)) return true;
  return ccw(a, b, c) != ccw(a, b, d) && ccw(c, d, a) != ccw(c, d, b);
}

////////////////////////////////////////////////////////////////
int N;

struct Event {
  lld x, e; Line l; // e=0: insert, e=1: delete
  bool operator <(const Event &E) const { return pair(x, e) < pair(E.x, E.e); }
};
vector<Event> E;

bool cmp(const Line &l, const Line &m) {
  lld x = max(l.s.x, m.s.x);
  return l.get_y(x) < m.get_y(x);
}
multiset<Line, decltype(&cmp)> S(&cmp);

bool solve() {
  for (auto [x, e, l]: E) {
    if (e == 0) {
      auto it = S.insert(l);
      if (it != S.begin() && intersect(*it, *prev(it))) return 1;
      if (next(it) != S.end() && intersect(*it, *next(it))) return 1;
    } else {
      auto it = S.find(l);
      if (it != S.begin() && next(it) != S.end() &&
        intersect(*prev(it), *next(it))) return 1;
      S.erase(it);
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    lld x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    Point s = {x1, y1}, e = {x2, y2};
    if (e < s) swap(s, e);
    Line l = {s, e};

    E.push_back({s.x, 0, l});
    E.push_back({e.x, 1, l});
  }
  sort(all(E));

  cout << solve() << endl;

  ////////////////////////////////
  return 0;
}
