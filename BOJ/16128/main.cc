#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

bool corner(lld x, lld y, lld L) { return (x == 0 || x == L-1) && (y == 0 || y == L-1); }

lld solve(lld L, lld a, lld b, lld c, lld d) {
  if (L == 1) return 0;
  if (corner(a, b, L) && corner(c, d, L) && a != c && b != d) return 2 * (L-1);

  lld H = L/2;
  lld sx = a/H, sy = b/H, ex = c/H, ey = d/H;
  if (sx == ex && sy == ey) return solve(H, a%H, b%H, c%H, d%H);
  
  lld ret = (sx != ex) + (sy != ey);
  ret += solve(H, a%H, b%H, sx?0:H-1, sy?0:H-1);
  ret += solve(H, c%H, d%H, ex?0:H-1, ey?0:H-1);
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  lld N, M; cin >> N >> M;
  lld a, b; cin >> a >> b; a--, b--;

  lld ans = 0;
  for (int i=0; i<M; i++) {
    lld c, d; cin >> c >> d; c--, d--;
    ans += solve(1LL << N, a, b, c, d);
    a = c, b = d;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
