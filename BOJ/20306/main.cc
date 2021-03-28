#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;

struct Point {
  lld x, y;
  Point(): x(0), y(0) {}
  Point(lld x, lld y): x(x), y(y) {}

  bool operator ==(Point a) const { return x == a.x && y == a.y; }
  bool operator !=(Point a) const { return !(*this == a); }
  bool operator <(Point a) const { return pair(x, y) < pair(a.x, a.y); }
  Point operator +(Point a) const { return {x+a.x, y+a.y}; }
  Point operator -(Point a) const { return {x-a.x, y-a.y}; }
  Point operator *(lld c) const { return {x*c, y*c}; }
  Point operator /(lld c) const { return {x/c, y/c}; }
  lld operator *(Point a) const { return x*a.x + y*a.y; }
};

ostream& operator <<(ostream& os, Point a) {
  return os << "(" << a.x << ", " << a.y << ")";
}
lld cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }
double angle(Point a) { return atan2(a.y, a.x); }

////////////////////////////////////////////////////////////////
int N, M, K;
Point origin;
vector<Point> P, A;
vector<lld> T;

bool cmp(Point a, Point b) { return angle(a) < angle(b); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;
  P.resize(N);
  cin >> origin.x >> origin.y;
  for (int i=0; i<N; i++) {
    cin >> P[i].x >> P[i].y;
    P[i] = P[i] - origin;
  }
  for (int i=0; i<M; i++) {
    lld x, y; cin >> x >> y;
    if (Point(x, y) == Point()) T.push_back(0);
    else A.push_back(Point(x, y) - origin);
  }
  sort(P.begin(), P.end(), cmp);
  sort(A.begin(), A.end(), cmp);

  int j = 0;
  for (int i=0; i<=N; i++) {
    auto p = P[(i+N-1)%N], q = P[i%N];
    while (j < A.size() && cross(p, A[j]) >= 0 && cross(A[j], q) >= 0) {
      T.push_back((cross(A[j], q-p)-1) / cross(p, q-p));
      j++;
    }
  }

  sort(T.begin(), T.end());
  cout << T[K-1] << endl;

  ////////////////////////////////
  return 0;
}
