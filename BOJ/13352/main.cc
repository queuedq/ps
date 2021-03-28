#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
struct Point { lld x, y; };
bool operator<(Point a, Point b) { return (pll){a.x, a.y} < (pll){b.x, b.y}; }
bool operator==(Point a, Point b) { return a.x == b.x && a.y == b.y; }
Point operator+(Point a, Point b) { return {a.x + b.x, a.y + b.y}; }
Point operator-(Point a, Point b) { return {a.x - b.x, a.y - b.y}; }
Point operator*(lld a, Point b) { return {a * b.x, a * b.y}; }
lld operator*(Point a, Point b) { return a.x * b.x + a.y * b.y; }
ostream& operator<<(ostream& os, Point a) { os << "{" << a.x << "," << a.y << "}"; return os; }
lld cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

const int MAXN = 1e5+5;
int N;
Point P[MAXN];

bool check(int a, int b) {
  vector<Point> Q;
  for (int i=0; i<N; i++) {
    if (cross(P[a]-P[i], P[b]-P[i]) == 0) continue;
    Q.push_back(P[i]);
  }
  if (Q.size() <= 2) return true;
  for (int i=2; i<Q.size(); i++) {
    if (cross(Q[i]-Q[0], Q[i]-Q[1]) != 0) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> P[i].x >> P[i].y;

  if (N == 1) {
    cout << "success" << endl;
    return 0;
  }

  for (int tries=0; tries<50; tries++) {
    int a = rand() % N;
    int b = rand() % N;
    if (a == b) continue;

    if (check(a, b)) {
      cout << "success" << endl;
      return 0;
    }
  }

  cout << "failure" << endl;

  ////////////////////////////////
  return 0;
}
