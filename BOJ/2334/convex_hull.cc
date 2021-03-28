#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

struct Point { lld x, y; };
bool operator<(Point a, Point b) { return (pll){a.x, a.y} < (pll){b.x, b.y}; }
bool operator==(Point a, Point b) { return a.x == b.x && a.y == b.y; }
Point operator+(Point a, Point b) { return {a.x + b.x, a.y + b.y}; }
Point operator-(Point a, Point b) { return {a.x - b.x, a.y - b.y}; }
Point operator*(lld a, Point b) { return {a * b.x, a * b.y}; }
lld operator*(Point a, Point b) { return a.x * b.x + a.y * b.y; }
ostream& operator<<(ostream& os, Point a) { os << "{" << a.x << "," << a.y << "}"; return os; }

////////////////////////////////////////////////////////////////
#define MAX_N 705

int T, N;
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

void input() {
  cin >> N;
  for (int i=0; i<N; i++) {
    double x, y; cin >> x >> y;
    P.push_back({(lld)round(x * 100), (lld)round(y * 100)});
  }

  sort(P.begin(), P.end());
  N = unique(P.begin(), P.end()) - P.begin();
  P.resize(N);
}

bool calc() {
  if (conv.size() == 1) return false;

  for (int i=0; i<conv.size(); i++) {
    auto [dx, dy] = conv[i] - conv[(i+1) % conv.size()];

    vector<Point> Q(N);
    Point mid = conv[i] + conv[(i+1) % conv.size()];
    for (int i = 0; i < N; i++) {
      Q[i] = 2*P[i] - mid;
      Q[i] = {dy*Q[i].x - dx*Q[i].y, dx*Q[i].x + dy*Q[i].y};
    }
    sort(Q.begin(), Q.end());

    vector<Point> st;
    bool onFold = false;
    for (int i=0; i<N; i++) {
      if (Q[i].y == 0) { onFold = true; break; }
      if (!st.empty() && st.back().x == Q[i].x && st.back().y == -Q[i].y) st.pop_back();
      else st.push_back(Q[i]);
    }

    if (!onFold && st.size() == 0) return true;
  }

  return false;
}

void reset() {
  P.clear();
  conv.clear();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> T;
  while (T--) {
    input();
    hull();

    cout << (calc() ? "YES" : "NO") << endl;
    reset();
  }

  ////////////////////////////////
  return 0;
}
