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
const int ST = 1<<16;
int N, X, Y;
// seg: slice -> lines / map: coord -> line / coord: 0 - x (vertical), 1 - y (horizontal)
map<int, int> seg[2][ST*2];

struct Cut {
  int x, i;
  bool operator<(const Cut &L) const { return x < L.x; }
};

void add_line(int dir, int s, int e, int x, int num) {
  for (s+=ST, e+=ST; s<e; s/=2, e/=2) {
    if (s&1) seg[dir][s++][x] = num;
    if (e&1) seg[dir][--e][x] = num;
  }
}

pair<Cut, Cut> get_range(int dir, int slice, int x) {
  Cut l = {-INF, 0}, r = {INF, 0};
  for (int n=ST+slice; n>0; n/=2) {
    auto &S = seg[dir][n];
    auto it = S.lower_bound(x);

    if (it != S.end()) {
      r = min(r, {it->first, it->second});
    }
    if (it != S.begin()) { it--;
      l = max(l, {it->first, it->second});
    }
  }
  return {l, r};
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> X >> Y >> N;

  // boundaries
  add_line(0, 0, Y, 0, 0); // left
  add_line(0, 0, Y, X, 0); // right
  add_line(1, 0, X, 0, -1); // bottom
  add_line(1, 0, X, Y, -1); // top

  multiset<int> rect = {X*Y};

  for (int i=1; i<=N; i++) {
    int x, y; cin >> x >> y;

    auto [L, R] = get_range(0, y, x); // left, right
    auto [D, U] = get_range(1, x, y); // bottom, top

    if (max(L.i, R.i) > max(D.i, U.i)) { // last ver -> cut hor
      add_line(1, L.x, R.x, y, i);
      rect.erase(rect.find((R.x - L.x) * (U.x - D.x)));
      rect.insert((R.x - L.x) * (y - D.x));
      rect.insert((R.x - L.x) * (U.x - y));

    } else { // last hor -> cut ver
      add_line(0, D.x, U.x, x, i);
      rect.erase(rect.find((R.x - L.x) * (U.x - D.x)));
      rect.insert((x - L.x) * (U.x - D.x));
      rect.insert((R.x - x) * (U.x - D.x));

    }
  }

  cout << *rect.rbegin() << " " << *rect.begin() << endl;

  ////////////////////////////////
  return 0;
}
