#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct Point { lld x, y; };
bool operator<(Point a, Point b) { if (a.x == b.x) { return a.y < b.y; } return a.x < b.x; }
Point operator+(Point a, Point b) { return {a.x + b.x, a.y + b.y}; }
Point operator-(Point a, Point b) { return {a.x - b.x, a.y - b.y}; }
Point operator*(lld a, Point b) { return {a * b.x, a * b.y}; }
lld operator*(Point a, Point b) { return a.x * b.x + a.y * b.y; }
bool operator==(Point a, Point b) { return a.x == b.x && a.y == b.y; }
ostream& operator<<(ostream& os, Point a) { os << "{" << a.x << "," << a.y << "}"; return os; }

////////////////////////////////////////////////////////////////
int N;
vector<Point> P, conv;
Point P0;

void input() {
  P.clear(); conv.clear();

  cin >> N;
  for (int i = 0; i < N; i++) {
    lld x, y; cin >> x >> y;
    P.push_back({x, y});
  }

  sort(P.begin(), P.end());
}

lld outer(Point a, Point b) { return a.x * b.y - a.y * b.x; }
lld ccw(Point a, Point b, Point c) { return outer(b - a, c - a); }
lld dist(Point a, Point b) { return (a - b) * (a - b); }

bool polarCmp(Point a, Point b) {
  lld theta = ccw(P0, a, b);
  if (theta == 0) { return dist(a, P0) < dist(b, P0); }
  return theta > 0;
}

void hull() {
  // Leftmost Point & Sort
  P0 = P[0];
  sort(next(P.begin()), P.end(), polarCmp);

  // Filter
  vector<Point> Q;
  Q.push_back(P0);
  for (int i = 1; i < P.size(); i++) {
    while (i < P.size()-1 && ccw(P0, P[i], P[i + 1]) == 0) { i++; }
    Q.push_back(P[i]);
  }

  // Convex Hull
  conv.push_back(Q[0]);
  conv.push_back(Q[1]);
  for (int i = 2; i < Q.size(); i++) {
    Point top = conv.back(), nextToTop = conv.rbegin()[1];
    while (ccw(nextToTop, top, Q[i]) <= 0) {
      conv.pop_back();
      top = conv.back();
      nextToTop = conv.rbegin()[1];
    }
    conv.push_back(Q[i]);
  }
}

lld area(Point p, Point q, Point r) {
  return abs(ccw(p, q, r));
}

Point convAt(int i) { return conv[i % conv.size()]; }

void calc() {
  lld maxArea = 0;

  for (int i = 0; i < conv.size(); i++) {
    int h1 = 0, h2 = 1;
    for (int j = 1; j < conv.size(); j++) {
      while (h1 < j) {
        lld A1 = area(conv[i], convAt(i+j), convAt(i+h1));
        lld A2 = area(conv[i], convAt(i+j), convAt(i+h1+1));
        if (A1 <= A2) { h1++; }
        else { break; }
      }

      h2 = max(h2, j);
      while (h2 < conv.size()) {
        lld A1 = area(conv[i], convAt(i+j), convAt(i+h2));
        lld A2 = area(conv[i], convAt(i+j), convAt(i+h2+1));
        if (A1 <= A2) { h2++; }
        else { break; }
      }

      lld S1 = area(conv[i], convAt(i+j), convAt(i+h1));
      lld S2 = area(conv[i], convAt(i+j), convAt(i+h2));
      maxArea = max(maxArea, S1 + S2);
    }
  }

  cout << maxArea / 2;
  if (maxArea % 2 == 1) { cout << ".5"; }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    input();
    hull();
    calc();
  }

  ////////////////////////////////
  return 0;
}
