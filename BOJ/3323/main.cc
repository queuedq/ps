#include <algorithm>
#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
struct Point {
  lld x, y;
  Point operator+(Point P) const { return {x+P.x, y+P.y}; }
  Point operator-(Point P) const { return {x-P.x, y-P.y}; }
  bool operator<(Point P) const {
    if (y*P.x == P.y*x) return x+y < P.x+P.y;
    return y*P.x > P.y*x; // clockwise
  }
};
ostream& operator<<(ostream &os, Point P) { return os << "(" << P.x << ", " << P.y << ")"; }

lld ccw(Point A, Point B, Point C) {
  return (A.x*B.y + B.x*C.y + C.x*A.y) - (A.y*B.x + B.y*C.x + C.y*A.x);
}

const int ST = 1<<17;
int K, M;
Point P[ST], L[ST], R[ST];
vector<Point> seg[ST*2]; // convex hulls

void hull(vector<Point> &H, int l, int r) {
  H.resize(r-l+1);
  H[0] = P[l], H[1] = P[l+1];
  int j = 2;
  for (int i=l+2; i<=r; i++) {
    while (j >= 2 && ccw(H[j-2], H[j-1], P[i]) <= 0) j--;
    H[j++] = P[i];
  }
  H.resize(j);
}

void build(int n, int nl, int nr) {
  if (nl == nr) { seg[n] = {P[nl]}; return; }
  hull(seg[n], nl, nr);

  int m = (nl+nr+1)/2;
  build(n*2, nl, m-1);
  build(n*2+1, m, nr);
}

bool query(int n, int nl, int nr, int l, int r, Point A, Point B) { // AB contains a point?
  if (nr < l || r < nl) return 0;
  if (l <= nl && nr <= r) {
    vector<Point> &H = seg[n];
    // find closest point to line AB
    int s = 0, e = sz(H);
    while (s+1 < e) {
      int m = (s+e)/2;
      if (ccw({0, 0}, B-A, H[m]-H[m-1]) >= 0) e = m;
      else s = m;
    }
    // point on the right of AB?
    return ccw(A, B, H[s]) < 0;
  }

  int m = (nl+nr+1)/2;
  return query(n*2, nl, m-1, l, r, A, B) || query(n*2+1, m, nr, l, r, A, B);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> K >> M;
  for (int i=0; i<K; i++) cin >> P[i].x >> P[i].y;
  for (int i=0; i<M; i++) {
    cin >> L[i].x >> L[i].y >> R[i].x >> R[i].y;
    if (R[i] < L[i]) swap(L[i], R[i]);
  }
  sort(P, P+K);

  // build segtree
  build(1, 0, ST-1);

  // query
  for (int i=0; i<M; i++) {
    int l = lower_bound(P, P+K, L[i]) - P;
    int r = lower_bound(P, P+K, R[i]) - P;
    bool ans = query(1, 0, ST-1, l, r-1, L[i], R[i]);
    cout << "NY"[ans] << endl;
  }

  ////////////////////////////////
  return 0;
}
