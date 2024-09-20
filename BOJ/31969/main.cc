#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N;

struct Point {
  lld x, y;
  Point operator-() const { return {-x, -y}; }
  Point operator-(const Point &P) const { return {x-P.x, y-P.y}; }
  Point operator*(const lld &c) const { return {x*c, y*c}; }
};
Point P[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> P[i].x >> P[i].y;
  for (int i=1; i<N; i++) P[i] = P[i] - P[0];

  Point V = P[1]; // first vector
  lld Y = 0; // second vector (x = 0)
  if (V.x < 0) V = -V;

  for (int i=2; i<N; i++) {
    if (P[i].x < 0) P[i] = -P[i];

    while (P[i].x) {
      lld q = V.x / P[i].x;
      V = V - P[i] * q;
      swap(V, P[i]);
    }

    Y = gcd(Y, P[i].y);
    if (Y) V.y %= Y; // prevent overflow
  }

  // area
  lld area = V.x * Y;
  cout << (area ? area : -1) << endl;

  ////////////////////////////////
  return 0;
}
