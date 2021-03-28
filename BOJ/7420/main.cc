#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

struct Point {
  lld x, y;
};
bool operator<(Point a, Point b) { if (a.x == b.x) { return a.y < b.y; } return a.x < b.x; }
Point operator+(Point a, Point b) { return {a.x + b.x, a.y + b.y}; }
Point operator-(Point a, Point b) { return {a.x - b.x, a.y - b.y}; }
Point operator*(lld a, Point b) { return {a * b.x, a * b.y}; }
lld operator*(Point a, Point b) { return a.x * b.x + a.y * b.y; }
bool operator==(Point a, Point b) { return a.x == b.x && a.y == b.y; }
ostream& operator<<(ostream& os, Point a) { os << "{" << a.x << "," << a.y << "}"; return os; }

////////////////////////////////////////////////////////////////
#define MAX_N 1005

int N;
lld L;
Point P[MAX_N], P0;
vector<Point> conv;

lld outer(Point a, Point b) {
  return a.x * b.y - a.y * b.x;
}

lld ccw(Point a, Point b) {
  return outer(a - P0, b - P0);
}

lld dist(Point a) {
  return a * a;
}

bool polarCmp(Point a, Point b) {
  lld theta = ccw(a, b);
  if (theta == 0) {
    return dist(a) < dist(b);
  } else {
    return theta > 0;
  }
}

void input() {
  cin >> N >> L;

  for (int i = 0; i < N; i++) {
    lld x, y;
    cin >> x >> y;
    P[i] = {x, y};
  }

  sort(P, P + N);
}

void hull() {
  // Leftmost Point & Sort
  P0 = P[0];
  sort(P + 1, P + N, polarCmp);

  // Filter
  Point Q[MAX_N];
  Q[0] = P[0];
  int M = 1;
  for (int i = 1; i < N; i++) {
    while (i < N - 1 && ccw(P[i], P[i + 1]) == 0) { i++; }
    Q[M] = P[i];
    M++;
  }

  if (M <= 2) {
    for (int i = 0; i < M; i++) { conv.push_back(Q[i]); }
    return;
  }

  // Convex Hull
  conv.push_back(Q[0]);
  conv.push_back(Q[1]);
  conv.push_back(Q[2]);
  for (int i = 3; i < M; i++) {
    Point dir = conv.back() - conv.rbegin()[1];
    while (outer(dir, Q[i] - conv.back()) <= 0) {
      conv.pop_back();
      dir = conv.back() - conv.rbegin()[1];
    }
    conv.push_back(Q[i]);
  }
}

lld calc() {
  double result = 0;
  for (int i = 0; i < conv.size(); i++) {
    double d = sqrt(dist(conv[i] - conv[(i + 1) % conv.size()]));
    result += d;
  }

  return round(result + 2 * M_PI * L);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  hull();
  cout << calc() << endl;

  ////////////////////////////////
  return 0;
}
