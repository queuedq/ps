#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
using lf = double;

////////////////////////////////////////////////////////////////
lf eps = 1e-12;

struct Point {
  lf x, y;
  Point operator+(Point P) { return {x+P.x, y+P.y}; }
  Point operator-(Point P) { return {x-P.x, y-P.y}; }
  Point operator*(lf F) { return {x*F, y*F}; }
  Point operator/(lf F) { return {x/F, y/F}; }
  lf operator*(Point P) { return x*P.x + y*P.y; } // dot product
  lf cross(Point P) { return x*P.y - P.x*y; } // cross product
  lf length() { return sqrt(x*x + y*y); }
};

ostream& operator<<(ostream &os, Point P) {
  return os << "(" << P.x << "," << P.y << ")";
}

struct Line {
  Point P, u; // u: direction vector
};

tuple<bool, lf, lf> inter(Line L, Line M) {
  // returns r, s where intersection = P + ru = Q + sv
  auto [P, u] = L;
  auto [Q, v] = M;

  // parallel
  if (u.cross(v) == 0) {
    lf r = ((Q-P) * u) / (u * u);
    lf s = ((P-Q) * v) / (v * v);
    if (u.cross(Q-P) != 0) return {false, 0, 0}; // does not meet (parallel)
    if (r < 0 && s < 0) return {false, 0, 0}; // does not meet
    if (r > 0 && s > 0) return {true, r/2, s/2}; // meets at midpoint
    if (r > 0) return {true, r, 0}; // meets at Q
    return {true, 0, s}; // meets at P
  }

  lf r = (Q-P).cross(v) / u.cross(v);
  lf s = (P-Q).cross(u) / v.cross(u);

  if (r < 0 || s < 0) return {false, 0, 0}; // does not meet
  return {true, r, s}; // intersection found
}

struct Event {
  // if snail b stops after tb, then snail a stops at ta (blocked by b)
  lf ta, tb; // ta > tb
  int a, b;
  bool operator<(Event E) const { return ta < E.ta; }
};

////////////////////////////////
const int MN = 1010;
int N;
lf L;
Line snail[MN], square[4];

vector<Event> E;
lf stop_time[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> L;
  for (int i=1; i<=N; i++) {
    lf x, y, p, q; cin >> x >> y >> p >> q;
    snail[i] = {{x, y}, {p-x, q-y}};
  }

  square[0] = {{0, 0}, {1, 0}};
  square[1] = {{L, 0}, {0, 1}};
  square[2] = {{L, L}, {-1, 0}};
  square[3] = {{0, L}, {0, -1}};

  // collect events
  for (int i=1; i<=N; i++) {
    for (int j=1; j<i; j++) {
      auto [meet, r, s] = inter(snail[i], snail[j]);
      if (!meet) continue;

      lf t1 = r * snail[i].u.length();
      lf t2 = s * snail[j].u.length();

      if (t1 < t2 + eps) E.push_back({t2, t1, j, i}); // snail j blocked by i
      if (t2 < t1 + eps) E.push_back({t1, t2, i, j}); // snail i blocked by j
    }

    // walls
    for (int j=0; j<4; j++) {
      auto [meet, r, s] = inter(snail[i], square[j]);
      if (!meet) continue;

      lf t = r * snail[i].u.length();
      E.push_back({t, 0, i, N+1});
    }
  }

  // simulate
  E.push_back({INFINITY, 0, 0, 0});
  sort(all(E));
  
  lf now = 0;
  vector<int> stopped;
  for (int i=1; i<=N+1; i++) stop_time[i] = INFINITY;

  for (auto [ta, tb, a, b]: E) {
    if (ta > now + eps) { // time advances
      for (auto i: stopped) stop_time[i] = now;
      stopped.clear();
      now = ta;
    }

    if (stop_time[a] < ta - eps) continue; // snail a stopped early
    if (stop_time[b] < tb - eps) continue; // snail b stopped early
    stopped.push_back(a);
  }

  lf ans = 0;
  for (int i=1; i<=N; i++) {
    // cout << i << ": " << stop_time[i] << endl;
    ans = max(ans, stop_time[i]);
  }
  cout << fixed << setprecision(2) << ans << endl;

  ////////////////////////////////
  return 0;
}
