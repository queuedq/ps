#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
const lld INF = 1e9;

struct Point {
  lld x, y;
  bool operator ==(const Point &P) const { return pll(x, y) == pll(P.x, P.y); }
  bool operator <(const Point &P) const { return x < P.x; }
};

lld N;
Point A[MN];
vector<pair<Point, lld>> E;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> A[i].x >> A[i].y;
  }

  for (int i=0; i<N+1; i++) {
    int j = (i+1)%N;
    if (A[i].y == A[j].y) {
      Point a = A[i], b = A[j];
      if (A[i].x > A[j].x) swap(a, b);
      E.push_back({a, 0});
      E.push_back({b, 1});
    }
  }

  sort(all(E));
  E.erase(unique(all(E)), E.end());

  lld l=-INF, r=INF, cnt=0;
  set<lld> ys;
  for (auto [p, t]: E) {
    if (t == 0) ys.insert(p.y);
    else ys.erase(p.y);
    if (ys.size() == 2) {
      // cout << *ys.begin() << " " << *prev(ys.end()) << endl;
      l = max(l, *ys.begin());
      r = min(r, *prev(ys.end()));
      if (l >= r) {
        cnt++;
        l = 
      }
    }
  }

  ////////////////////////////////
  return 0;
}
