#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
int N;

struct Point {
  lld x, y, c, i;
  bool operator <(const Point &P) const { return pll(x, y) < pll(P.x, P.y); }
  bool operator ==(const Point &P) const { return pll(c, i) == pll(P.c, P.i); }
};
vector<Point> P, match;

lld ccw(Point P, Point Q, Point R) {
  return P.x*Q.y + Q.x*R.y + R.x*P.y - P.y*Q.x - Q.y*R.x - R.y*P.x;
}

vector<Point> convex_hull(vector<Point> P) {
  if (sz(P) <= 1) return P;
  sort(all(P));
  vector<Point> Q(sz(P)+1);

  int s = 0, i = 0;
  for (auto d: {0, 1}) {
    for (auto p: P) {
      while (i-2 >= s && ccw(Q[i-2], Q[i-1], p) <= 0) i--;
      Q[i++] = p;
    }
    s = --i; reverse(all(P));
  }

  Q.resize(i);
  return Q;
}

tuple<bool, Point, Point> diff_color(vector<Point> &Q) {
  for (int i=1; i<sz(Q); i++) {
    if (Q[i-1].c != Q[i].c) {
      if (Q[i-1].c == 1) return {true, Q[i-1], Q[i]};
      else return {true, Q[i], Q[i-1]};
    }
  }
  return {false, {}, {}};
}

void dnc(vector<Point> P) {
  if (sz(P) == 0) return;
  sort(all(P));
  vector<Point> Q = convex_hull(P);
  auto [diff, A, B] = diff_color(Q);

  if (diff) {
    match[A.i] = B;
    P.erase(find(all(P), A));
    P.erase(find(all(P), B));
    dnc(P);

  } else {
    vector<Point> P0, P1;
    int i = 0, cnt = 0;
    for (; i<sz(P); i++) {
      cnt += (P[i].c == 1) ? 1 : -1;
      if (cnt == 0) break;
    }
    for (int j=0; j<=i; j++) P0.push_back(P[j]);
    for (int j=i+1; j<sz(P); j++) P1.push_back(P[j]);
    dnc(P0);
    dnc(P1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  P.resize(N*4); match.resize(N*2);
  for (int i=0; i<N; i++) {
    lld x, y; cin >> x >> y;
    P[i] = {x, y, 1, i};
    P[i+N] = {x, y, 1, i+N};
  }
  for (int i=0; i<N*2; i++) {
    lld x, y; cin >> x >> y;
    P[i+N*2] = {x, y, 2, i};
  }

  dnc(P);
  for (int i=0; i<N; i++) {
    cout << match[i].i+1 << " " << match[i+N].i+1 << endl;
  }

  ////////////////////////////////
  return 0;
}
