#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 3030;
int N, tri[MN][MN], D[MN], E[MN];

struct Point { lld x, y; };
Point A[MN];

lld ccw(Point A, Point B, Point C) {
  return A.x*B.y + B.x*C.y + C.x*A.y - A.y*B.x - B.y*C.x - C.y*A.x;
}

lld dist2(Point A, Point B) {
  return (A.x-B.x) * (A.x-B.x) + (A.y-B.y) * (A.y-B.y);
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
  sort(A+1, A+N, [&](Point P, Point Q) { return ccw(A[0], P, Q) > 0; });

  // get possible triangles
  for (int i=1; i<N; i++) {
    vector<int> ord;
    for (int j=i+1; j<N; j++) {
      if (ccw(A[0], A[i], A[j]) == 0) continue;
      ord.push_back(j);
    }
    sort(all(ord), [&](int a, int b) { // clockwise around A[i]
      lld c = ccw(A[i], A[a], A[b]);
      if (c == 0) return dist2(A[i], A[a]) > dist2(A[i], A[b]); // farthest first
      return c < 0;
    });
    
    if (ord.empty()) continue;
    int m = ord[0]; // inner point candidate
    for (auto j: ord) {
      if (ccw(A[0], A[m], A[j]) > 0) tri[i][j] = m; // A[m] in (A[0], A[i], A[j])
      m = min(m, j);
    }
  }
  
  // DP
  for (int i=1; i<N; i++) {
    for (int j=1; j<i; j++) {
      if (tri[j][i] && D[j]+1 > D[i]) { D[i] = D[j] + 1; E[i] = j; }
    }
  }

  vector<Point> ans;
  int i = max_element(D+1, D+N) - D;
  while (i) {
    ans.push_back(A[i]);
    if (E[i]) ans.push_back(A[tri[E[i]][i]]);
    i = E[i];
  }
  ans.push_back(A[0]);
  reverse(all(ans));

  cout << sz(ans) << endl;
  for (auto [x, y]: ans) cout << x << " " << y << endl;

  ////////////////////////////////
  return 0;
}
