#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using Int = __int128_t;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
const lld MOD = 1e9+7;
int N;

struct Point {
  Int x, y;
  Point operator-() const { return {-x, -y}; }
  Point operator-(const Point &P) const { return {x-P.x, y-P.y}; }
  Point operator*(const Int &c) const { return {x*c, y*c}; }
};
Point P[MN];

lld modpow(lld a, lld e, lld m) {
  if (e == 0) return 1;
  lld r = modpow(a, e/2, m);
  if (e%2 == 0) return r*r % m;
  return (r*r % m) * a % m;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    lld x, y; cin >> x >> y;
    P[i] = {x, y};
  }

  Point V = P[0]; // first vector
  Int Y = 0; // second vector (x = 0)
  if (V.x < 0) V = -V;

  for (int i=1; i<N; i++) {
    if (P[i].x < 0) P[i] = -P[i];
    while (P[i].x) {
      Int q = V.x / P[i].x;
      V = V - P[i] * q;
      swap(V, P[i]);
    }
    
    if (P[i].y < 0) P[i] = -P[i];
    while (P[i].y) {
      Int q = Y / P[i].y;
      Y = Y - P[i].y * q;
      swap(Y, P[i].y);
    }

    if (Y) V.y %= Y; // prevent overflow
  }

  // area
  lld area = (lld)V.x * (lld)(Y % MOD) % MOD;
  if (area) cout << modpow(area, MOD-2, MOD) << endl;
  else cout << 0 << endl;

  ////////////////////////////////
  return 0;
}
