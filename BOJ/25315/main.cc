#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2505;
int N;

struct Point { lld x, y; };

bool ccw(Point &A, Point &B, Point &C) {
  return (A.x*B.y + B.x*C.y + C.x*A.y - A.y*B.x - B.y*C.x - C.y*A.x) > 0;
}

struct Line {
  Point A, B; lld w;
  bool inter(Line &L) {
    return (ccw(A, B, L.A) ^ ccw(A, B, L.B)) && (ccw(L.A, L.B, A) ^ ccw(L.A, L.B, B));
  }
};
Line L[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    lld x1, y1, x2, y2, w;
    cin >> x1 >> y1 >> x2 >> y2 >> w;
    L[i] = {{x1, y1}, {x2, y2}, w};
  }
  
  lld ans = 0;
  for (int i=0; i<N; i++) {
    ans += L[i].w;
    for (int j=i+1; j<N; j++) {
      if (L[i].inter(L[j])) ans += min(L[i].w, L[j].w);
    }
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
