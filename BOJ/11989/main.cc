#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<18;
int N, Q;

struct Point {
  lld x, y;
  Point operator+(Point P) const { return {x+P.x, y+P.y}; }
  Point operator-(Point P) const { return {x-P.x, y-P.y}; }
};

struct SegTree {
  Point offset;
  Point seg[ST*2];

  void init() {
    offset = {0, 0};
    fill_n(seg+ST, ST, Point{1, 0});
    seg[ST] = {0, 0};
    for (int n=ST-1; n>0; n--) seg[n] = seg[n*2] + seg[n*2+1];
  }

  void add_left(int i, Point P) { // [0, i)
    offset = offset + P;
    for (i+=ST; i>0; i/=2) seg[i] = seg[i] - P;
  }

  void add_right(int i, Point P) { // [i, ST)
    for (i+=ST; i>0; i/=2) seg[i] = seg[i] + P;
  }

  Point get(int i) { // [0, i] delta sum
    Point P = offset;
    for (i+=ST+1; i>0; i/=2) {
      if (i&1) P = P + seg[--i];
    }
    return P;
  }

  int find(lld k, bool forward) { return find(1, offset, k, forward); }
  int find(int n, Point offset, lld k, bool forward) {
    if (n >= ST) return n-ST;
    Point P = offset + seg[n*2];

    // forward slant (/): x-y >= k
    // backward slant (\): x+y >= k
    if ((forward ? P.x-P.y : P.x+P.y) >= k)
      return find(n*2, offset, k, forward);
    else
      return find(n*2+1, P, k, forward);
  }
};
SegTree seg;

struct Query { lld x, d, l; };
vector<Query> qry;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> Q;
  for (int i=0; i<Q; i++) {
    lld x, d, l; cin >> x >> d >> l;
    qry.push_back({x, d, l});
  }
  reverse(all(qry));

  seg.init();
  for (auto [x, d, l]: qry) {
    if (d == 1) { // forward slant (/)
      int i = seg.find(x, true);
      seg.add_left(i, {-l, -l});
    } else { // backward slant (\)
      int i = seg.find(x, false);
      seg.add_right(i, {l, -l});
    }
  }

  for (int i=0; i<N; i++) {
    cout << -seg.get(i).y << endl;
  }

  ////////////////////////////////
  return 0;
}
