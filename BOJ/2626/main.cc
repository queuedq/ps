#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

template <class T>
struct Vec {
  T x, y;
  Vec(): x(0), y(0) {}
  Vec(T x, T y): x(x), y(y) {}

  bool operator ==(Vec a) const { return x == a.x && y == a.y; }
  bool operator !=(Vec a) const { return !(*this == a); }
  bool operator <(Vec a) const { return pair(x, y) < pair(a.x, a.y); }
  Vec operator +(Vec a) const { return {x+a.x, y+a.y}; }
  Vec operator -(Vec a) const { return {x-a.x, y-a.y}; }
  Vec operator *(T c) const { return {x*c, y*c}; }
  Vec operator /(T c) const { return {x/c, y/c}; }
  T operator *(Vec a) const { return x*a.x + y*a.y; }
};

using Point = Vec<double>;

ostream& operator <<(ostream& os, Point a) {
  return os << "(" << a.x << ", " << a.y << ")";
}
double length(Point a) { return sqrt(a*a); }
Point ortho(Point a) { return {a.y, -a.x}; }

using Point = Vec<double>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
int N;
vector<Point> A;
struct Circle { Point c; double r; };

bool contains(Circle C, Point p) { return length(p-C.c) <= C.r; }

Point circumcenter(Point a, Point b, Point c) {
  Point m1 = (a+b)/2, m2 = (a+c)/2;
  Point v1 = ortho(b-a), v2 = ortho(c-a);
  double k = ((m2-m1)*(c-a)) / (v1*(c-a));
  return m1 + v1*k;
}

Circle trivial(vector<Point> R) {
  if (R.size() == 0) return {{0, 0}, 0};
  if (R.size() == 1) return {R[0], 0};
  if (R.size() == 2) return {(R[0]+R[1])/2, length(R[0]-R[1])/2};
  if (contains(trivial({R[0], R[1]}), R[2])) return trivial({R[0], R[1]});
  if (contains(trivial({R[1], R[2]}), R[0])) return trivial({R[1], R[2]});
  if (contains(trivial({R[2], R[0]}), R[1])) return trivial({R[2], R[0]});
  Point C = circumcenter(R[0], R[1], R[2]);
  return {C, length(R[0]-C)};
}

Circle welzl(const vector<Point> &P, vector<Point> R, int n) {
  if (n == 0 || R.size() == 3) return trivial(R);
  Circle D = welzl(P, R, n-1);
  if (contains(D, P[n-1])) return D;
  R.push_back(P[n-1]);
  return welzl(P, R, n-1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  A.resize(N);
  for (int i=0; i<N; i++) cin >> A[i].x >> A[i].y;

  shuffle(A.begin(), A.end(), default_random_engine());
  Circle C = welzl(A, {}, N);
  cout << fixed << setprecision(3);
  cout << C.c.x << " " << C.c.y << endl;
  cout << C.r << endl;

  ////////////////////////////////
  return 0;
}
