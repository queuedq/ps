#include <bits/stdc++.h>
#include <iomanip>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
using llf = long double;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N;

struct Point { lld x, y; };
Point P[MN];

lld ccw(Point A, Point B, Point C) {
  return (A.x*B.y + B.x*C.y + C.x*A.y) - (A.y*B.x + B.y*C.x + C.y*A.x);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> P[i].x >> P[i].y;

  llf A = 0; // area * 2
  for (int i=2; i<N; i++) {
    A += ccw(P[1], P[i], P[i+1]);
  }

  llf B = 0; // half area * 2
  int k = 0; llf r = 0;
  for (int i=2; i<N; i++) {
    llf tri = ccw(P[1], P[i], P[i+1]);
    if (B + tri >= A/2) {
      k = i;
      r = (A/2 - B) / tri;
      break;
    }
    B += tri;
  }

  cout << "YES" << endl;
  cout << fixed << setprecision(12) << 1 << " " << 0 << endl;
  cout << fixed << setprecision(12) << k << " " << r << endl;

  ////////////////////////////////
  return 0;
}
