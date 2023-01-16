#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

struct Frac {
  lld p, q;
  Frac(lld p, lld q): p(p), q(q) {
    if (q < 0) this->p = -p, this->q = -q;
  }
  bool operator <(const Frac F) const { return p * F.q < F.p * q; }
};

struct Point {
  lld x, y;
  Point operator +(const Point P) const { return {x+P.x, y+P.y}; }
};

struct Line {
  Point P, V; // start at P, direction V
};

pair<Frac, Frac> linear_eq(lld a, lld b, lld u, lld c, lld d, lld v) {
  // ax + by = u
  // cx + dy = v
  // Crammer's rule
  lld det = a*d - b*c;
  return {Frac(u*d - b*v, det), Frac(a*v - u*c, det)};
}

Frac inter_t(Line L, Line M) { // intersection position in line L
  // L.P + L.V * t = M.P + M.V * u
  auto [t, u] = linear_eq(
    L.V.x, -M.V.x, M.P.x - L.P.x,
    L.V.y, -M.V.y, M.P.y - L.P.y
  );
  return t;
}

lld ccw(Point P, Point Q, Point R) {
  return (P.x * Q.y + Q.x * R.y + R.x * P.y) - (P.y * Q.x + Q.y * R.x + R.y * P.x);
}

const int MN = 2020;
int N, ans = MN;
Point S;
Line L0[MN], L1[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> S.x >> S.y;
  for (int i=0; i<N; i++) {
    int x1, y1, x2, y2, a, b;
    cin >> x1 >> y1 >> x2 >> y2 >> a >> b;
    L0[i] = {{x1, y1}, {x2-x1, y2-y1}};
    L1[i] = {{x1+a, y1+b}, {x2-x1, y2-y1}};
  }

  for (int i=0; i<N; i++) {
    vector<int> diff(N);
    int tot = 0;
    for (int j=0; j<N; j++) {
      if (i == j) continue;
      bool s0 = ccw(L0[j].P, L0[j].P + L0[j].V, S) > 0; // start at left
      bool s1 = ccw({0, 0}, L0[j].V, L1[i].V) < 0; // infinite point at left
      diff[j] = s0 != s1;
      tot += diff[j];
    }

    vector<pair<Frac, int>> E;
    for (int j=0; j<N; j++) {
      if (i == j) continue;
      E.push_back({inter_t(L1[i], L1[j]), j});
    }
    sort(all(E));

    ans = min(ans, tot);
    for (int k=0; k<N-1; k++) {
      auto [t, j] = E[k];
      tot -= diff[j];
      diff[j] ^= 1;
      tot += diff[j];
      if (k == N-2 || t < E[k+1].first) ans = min(ans, tot);
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
