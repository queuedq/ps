#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct Point {
  lld x, y, i;
  bool operator <(const Point &P) const { return pll(x, y) < pll(P.x, P.y); }
  bool operator ==(const Point &P) const { return pll(x, y) == pll(P.x, P.y); }
};

ostream& operator <<(ostream &os, Point P) {
  return os << "(" << P.x << "," << P.y << ")";
}

lld ccw(Point P, Point Q, Point R) {
  return (P.x*Q.y + Q.x*R.y + R.x*P.y) - (P.y*Q.x + Q.y*R.x + R.y*P.x);
}

vector<Point> convex_hull(vector<Point> &P) {
  int N = sz(P), j = 0;
  sort(all(P));
  vector<Point> Q(N+1);
  for (auto d: {0, 1}) {
    for (int i=0, s=j; i<N; i++) {
      while (j-s >= 2 && ccw(Q[j-2], Q[j-1], P[i]) <= 0) j--;
      Q[j++] = P[i];
    }
    j--; reverse(all(P));
  }
  Q.resize(j);
  return Q;
}

lld area2(const vector<Point> &P) {
  lld N = sz(P), res = 0;
  for (int i=1; i<N-1; i++) res += ccw(P[0], P[i], P[i+1]);
  return res;
}

bool point_in_tri(Point A, Point P, Point Q, Point R) {
  return ccw(A, P, Q) >= 0 && ccw(A, Q, R) >= 0 && ccw(A, R, P) >= 0;
}

void print_area(lld a) {
  cout << a/2 << (a%2 ? ".500" : ".000") << endl;
}

////////////////////////////////////////////////////////////////
const int MN = 101010;
lld N, M, H_idx[MN];
vector<Point> A, H;
vector<Point> cand[MN]; // new hull point candidates when point i removed

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  A.resize(N);
  for (int i=0; i<N; i++) { cin >> A[i].x >> A[i].y; A[i].i = i; }

  H = convex_hull(A); M = sz(H);
  fill(H_idx, H_idx+N, -1);
  for (int j=0; j<M; j++) H_idx[H[j].i] = j;
  
  // get candidates
  sort(all(A), [](Point P, Point Q) -> bool { // be careful: P or Q can be H[0]
    if (P == H[0]) return 1;
    if (Q == H[0]) return 0;
    return ccw(H[0], P, Q) > 0;
  });

  for (int i=0, j=2; i<N; i++) {
    if (H_idx[A[i].i] != -1) continue;
    while (j < M && ccw(H[0], A[i], H[j]) < 0) j++;
    if (point_in_tri(A[i], H[j-2], H[j-1], H[j])) cand[j-1].push_back(A[i]);
    if (point_in_tri(A[i], H[j-1], H[j], H[(j+1)%M])) cand[j].push_back(A[i]);
    if (point_in_tri(A[i], H[0], H[1], H[M-1])) cand[0].push_back(A[i]);
  }

  // get ans
  sort(all(A), [](Point P, Point Q) { return P.i < Q.i; });
  lld tot = area2(H);
  for (int i=0; i<N; i++) {
    int j = H_idx[i];
    if (j == -1) { print_area(tot); continue; }

    Point prv = H[(j-1+M)%M], nxt = H[(j+1)%M];
    lld tri = area2({prv, H[j], nxt});

    vector<Point> B = {prv, nxt};
    for (auto b: cand[j]) B.push_back(b);
    lld bulge = area2(convex_hull(B));
    print_area(tot - tri + bulge);
  }

  ////////////////////////////////
  return 0;
}
