#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2020;

struct Point {
  lld x, y;
  bool operator <(const Point &P) const { return pll(x, y) < pll(P.x, P.y); }
  Point operator +(const Point &P) const { return {x+P.x, y+P.y}; }
  Point operator -(const Point &P) const { return {x-P.x, y-P.y}; }
};
lld cross(Point P, Point Q) { return P.x*Q.y - P.y*Q.x; }
double area(Point P, Point Q, Point R) { return abs(cross(Q-P, R-P)) / 2.0; }

struct Line {
  int i, j; Point V;
  // sort by y/x
  bool operator <(const Line &L) const {
    lld l = V.y * L.V.x, r = L.V.y * V.x;
    return tie(l, i, j) < tie(r, L.i, L.j);
  }
};

int N;
vector<Point> P;
vector<Line> L;
int pos[MN];

void solve() {
  cin >> N;
  if (N == 0) exit(0);

  P.resize(N);
  for (int i=0; i<N; i++) cin >> P[i].x >> P[i].y;
  sort(all(P));
  for (int i=0; i<N; i++) pos[i] = i;

  L.clear();
  for (int i=0; i<N; i++)
    for (int j=i+1; j<N; j++)
      L.push_back({i, j, P[j]-P[i]});
  sort(all(L));

  double mn = INFINITY, mx = -INFINITY;
  for (auto [i, j, V]: L) {
    if (pos[i] > pos[j]) swap(i, j);
    // assert(pos[i]+1 == pos[j]);

    if (pos[i] > 0) {
      mn = min(mn, area(P[pos[i]], P[pos[j]], P[pos[i]-1]));
      mx = max(mx, area(P[pos[i]], P[pos[j]], P[0]));
    }
    if (pos[j] < N-1) {
      mn = min(mn, area(P[pos[i]], P[pos[j]], P[pos[j]+1]));
      mx = max(mx, area(P[pos[i]], P[pos[j]], P[N-1]));
    }

    swap(P[pos[i]], P[pos[j]]);
    swap(pos[i], pos[j]);
  }

  cout << fixed << setprecision(1) << mn << " " << mx << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  while (1) solve();

  ////////////////////////////////
  return 0;
}
