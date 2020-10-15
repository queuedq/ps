#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct Point {
  double x, y;
  Point(): x(0), y(0) {}
  Point(double x, double y): x(x), y(y) {}
  double length();
};
bool operator==(Point a, Point b) { return a.x == b.x && a.y == b.y; }
bool operator!=(Point a, Point b) { return !(a == b); }
Point operator+(Point a, Point b) { return {a.x + b.x, a.y + b.y}; }
Point operator-(Point a, Point b) { return {a.x - b.x, a.y - b.y}; }
Point operator*(double c, Point a) { return {c * a.x, c * a.y}; }
double operator*(Point a, Point b) { return a.x * b.x + a.y * b.y; }
ostream& operator<<(ostream& os, Point a) { os << "(" << a.x << ", " << a.y << ")"; return os; }

double Point::length() { return sqrt(*this * *this); }

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
int N;
Point A[MAXN];

pair<double, int> radius(Point C) {
  double ans = 0;
  int idx = 0;
  for (int i=0; i<N; i++) {
    double d = (A[i] - C).length();
    if (ans < d) { ans = d; idx = i; }
  }
  return {ans, idx};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i].x >> A[i].y;

  Point C(0, 0);
  double step = 0.2;
  double rate = 0.998;
  for (int t=0; t<100000; t++) {
    auto [r, i] = radius(C);
    C = C + step * (A[i]-C);
    step *= rate;
  }

  auto [r, i] = radius(C);
  cout << fixed << setprecision(3);
  cout << C.x << " " << C.y << endl;
  cout << r << endl;

  ////////////////////////////////
  return 0;
}
