#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9;
const int ST = 1<<17;
int N, X, Y;
// seg: slice -> lines / coord: 0 - x (vertical), 1 - y (horizontal)
set<int> seg[2][ST*2];

void add_line(int dir, int s, int e, int x) {
  for (s+=ST, e+=ST; s<e; s/=2, e/=2) {
    if (s&1) seg[dir][s++].insert(x);
    if (e&1) seg[dir][--e].insert(x);
  }
}

pii get_range(int dir, int slice, int x) {
  int l = -INF, r = INF;
  for (int n=ST+slice; n>0; n/=2) {
    auto &S = seg[dir][n];
    auto it = S.lower_bound(x);
    if (it != S.end()) r = min(r, *it);
    if (it != S.begin()) l = max(l, *--it);
  }
  return {l, r};
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> X >> Y >> N;

  // boundaries
  add_line(0, 0, Y, 0); // left
  add_line(0, 0, Y, X); // right
  add_line(1, 0, X, 0); // bottom
  add_line(1, 0, X, Y); // top

  for (int i=1; i<=N; i++) {
    int x, y, d; cin >> x >> y >> d;
    lld A1, A2;

    auto [L, R] = get_range(0, y, x); // left, right
    auto [D, U] = get_range(1, x, y); // bottom, top

    if (d == 1) { // hor
      add_line(1, L, R, y);
      A1 = (lld)(R - L) * (y - D);
      A2 = (lld)(R - L) * (U - y);
    } else { // ver
      add_line(0, D, U, x);
      A1 = (lld)(x - L) * (U - D);
      A2 = (lld)(R - x) * (U - D);
    }

    if (A1 > A2) swap(A1, A2);
    cout << A1 << " " << A2 << endl;
  }

  ////////////////////////////////
  return 0;
}
