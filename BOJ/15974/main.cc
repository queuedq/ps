#include <algorithm>
#include <bits/stdc++.h>
#include <ostream>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define X first
#define Y second
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 3030;
const int INF = 1e9;
int N, angle[2][MN][MN];
pii D[2][MN][MN], E[2][MN][MN];
// D[turn][P][Q]
// E[turn][P][angle_index]: prefix/suffix max
vector<int> ord[MN];

struct Point { lld x, y; };
Point A[MN];

lld ccw(Point A, Point B, Point C) {
  return A.x*B.y + B.x*C.y + C.x*A.y - A.y*B.x - B.y*C.x - C.y*A.x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  int o = 0;
  for (int i=0; i<N; i++) {
    cin >> A[i].x >> A[i].y;
    if (A[i].y < A[o].y) o = i;
  }
  swap(A[0], A[o]);
  sort(A+1, A+N, [&](Point P, Point Q) { return ccw(A[0], P, Q) < 0; }); // cw

  // get ord, angle index
  for (int i=1; i<N; i++) {
    vector<int> idx;
    for (int j=1; j<N; j++) {
      if (ccw(A[0], A[i], A[j]) > 0) ord[i].push_back(j);
      if (ccw(A[0], A[i], A[j]) < 0) idx.push_back(j);
    }

    // ccw around A[i]
    sort(all(ord[i]), [&](int a, int b) { return ccw(A[i], A[a], A[b]) > 0; });
    sort(all(idx), [&](int a, int b) { return ccw(A[i], A[a], A[b]) > 0; });

    // get angles
    int l = 0, r = 0;
    for (auto x: idx) {
      while (l < sz(ord[i]) && ccw(A[x], A[i], A[ord[i][l]]) < 0) l++;
      while (r < sz(ord[i]) && ccw(A[x], A[i], A[ord[i][r]]) <= 0) r++;
      angle[0][x][i] = l;
      angle[1][x][i] = r;
    }
  }
  
  // DP
  for (int i=1; i<N; i++) {
    fill(D[0][i], D[0][i]+i, pii(-INF, 0));
    fill(D[1][i], D[1][i]+i, pii(-INF, 0));
  }

  for (int i=1; i<N; i++) {
    for (int j=1; j<i; j++) {
      if (ccw(A[0], A[i], A[j]) == 0) continue;

      int l = angle[0][i][j], r = angle[1][i][j];
      D[0][i][j] = E[1][j][r]; // down
      D[1][i][j] = {E[0][j][l].X + 1, E[0][j][l].Y}; // up
    }

    // prefix/suffix max
    int s = sz(ord[i]);

    E[0][i][0] = {-INF, 0};
    for (int k=0; k<s; k++) {
      E[0][i][k+1] = max(E[0][i][k], {D[0][i][ord[i][k]].X, ord[i][k]});
    }

    E[1][i][s] = {0, 0}; // allow down (0) without up
    for (int k=s-1; k>=0; k--) {
      E[1][i][k] = max(E[1][i][k+1], {D[1][i][ord[i][k]].X, ord[i][k]});
    }
  }

  // find best
  int i0 = 1;
  for (int i=1; i<N; i++) {
    if (E[1][i][0] > E[1][i0][0]) i0 = i;
  }
  int j0 = E[1][i0][0].Y;
  if (j0 == 0) { cout << 0 << endl; return 0; }

  // traceback
  vector<Point> ans = {A[0]};
  int i = i0, j = j0;
  while (j != 0) {
    ans.push_back(A[i]);
    ans.push_back(A[j]);
    int i1 = D[1][i][j].Y;
    int j1 = D[0][j][i1].Y;
    i = i1, j = j1;
  }
  ans.push_back(A[i]);

  cout << sz(ans) << endl;
  for (auto [x, y]: ans) cout << x << " " << y << endl;

  ////////////////////////////////
  return 0;
}
