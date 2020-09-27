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
double length(Point a) { return sqrt(a * a); }
double angle(Point a, Point b) {
  double c = a * b / length(a) / length(b);
  double s = cross(a, b) / length(a) / length(b);
  return atan2(s, c);
}

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N;
Point P[MAXN];

void solve() {
  cin >> N;
  for (int i=0; i<N; i++) cin >> P[i].x >> P[i].y;

  int l = 0, r = 0;
  for (int i=1; i<N; i++) {
    bool b1 = cross(P[1]-P[0], P[i-1]-P[i]) >= 0;
    bool b2 = cross(P[N-1]-P[0], P[(i+1)%N]-P[i]) <= 0;
    if (b1 && b2) {
      if (l == 0) l = i;
      r = i;
    }
  }
  r = (r+1)%N;
  cout << l << " " << r << endl;

  lld ans = (r-l+N) % N;

  for (int i=1; i<N; i++) {
    while (true) {
      bool b1 = cross(P[(i+1)%N]-P[i], P[l-1]-P[l]) >= 0;
      bool b2 = cross(P[i-1]-P[i], P[(l+1)%N]-P[l]) <= 0;
      if (b1 && b2) break;
      l = (l+1)%N;
    }
    while (true) {
      bool b1 = cross(P[(i+1)%N]-P[i], P[r-1]-P[r]) >= 0;
      bool b2 = cross(P[i-1]-P[i], P[(r+1)%N]-P[r]) <= 0;
      if (b1 && b2) r = (r+1)%N;
      else break;
    }
    ans += (r-l+N) % N;
    cout << l << " " << r << endl;
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve();
  }

  ////////////////////////////////
  return 0;
}
