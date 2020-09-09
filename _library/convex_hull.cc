#include "template.h"
#include "point.cc"

int N;
vector<Point> P, conv;

lld cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
lld ccw(Point a, Point b, Point c) { return cross(b - a, c - a); }
lld dist(Point a, Point b) { return (a - b) * (a - b); }

auto polarCmp(Point P0) {
  return [P0](Point a, Point b) {
    lld theta = ccw(P0, a, b);
    if (theta == 0) return dist(a, P0) < dist(b, P0);
    return theta > 0;
  };
}

void hull() {
  // Leftmost Point & Sort
  Point P0 = P[0];
  sort(P.begin()+1, P.end(), polarCmp(P0));

  // Filter
  vector<Point> Q;
  Q.push_back(P0);
  for (int i = 1; i < P.size(); i++) {
    while (i < P.size()-1 && ccw(P0, P[i], P[i+1]) == 0) i++;
    Q.push_back(P[i]);
  }

  // Convex Hull
  if (Q.size() == 0) return;
  if (Q.size() == 1) return conv.push_back(Q[0]);
  conv.push_back(Q[0]);
  conv.push_back(Q[1]);
  for (int i = 2; i < Q.size(); i++) {
    Point A = conv.back(), B = conv.rbegin()[1];
    while (ccw(B, A, Q[i]) <= 0) {
      conv.pop_back();
      A = conv.back();
      B = conv.rbegin()[1];
    }
    conv.push_back(Q[i]);
  }
}

void example() {
  P.clear();
  conv.clear();

  cin >> N;
  for (int i=0; i<N; i++) {
    lld x, y; cin >> x >> y;
    P.push_back({x, y});
  }

  sort(P.begin(), P.end());
  hull();
}
