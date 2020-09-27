#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

lld gcd(lld a, lld b) {
  while (b > 0) { a = a % b; swap(a, b); }
  return a;
}

pll egcd(lld a, lld b) {
  lld ax = 1, ay = 0, bx = 0, by = 1;
  while (b > 0) {
    lld q = a / b;
    a -= b * q; ax -= bx * q; ay -= by * q;
    swap(a, b); swap(ax, bx); swap(ay, by);
  }
  return {ax, ay};
}

lld invmod(lld a, lld m) {
  return (egcd(a, m).first + m) % m;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    lld M, N, x, y;
    cin >> M >> N >> x >> y;
    x--; y--;

    auto [u, v] = egcd(M, N);
    lld g = u*M + v*N;
    lld l = M*N/g;

    if (x % g != y % g) { cout << -1 << endl; continue; }

    lld ans = ((x*v*N + y*u*M) / g % l + l) % l;
    cout << ans+1 << endl;
  }

  ////////////////////////////////
  return 0;
}
