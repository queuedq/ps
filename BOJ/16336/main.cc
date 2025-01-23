#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MQ = 101010;
const int MX = MQ*2; // at most 2Q different x coords

struct Point { int q, x, y; };
struct Rect { int q, l, r, y, v; };

struct Fenwick {
  int bit[MX*2];
  vector<pii> history;

  void add(int i, int x) { // 0-based
    history.push_back({i, x});
    for (i+=1; i<MX; i+=i&-i) bit[i] += x;
  }

  int sum(int i) { // 0-based
    int s = 0;
    for (i+=1; i>0; i-=i&-i) s += bit[i];
    return s;
  }

  void reset() {
    for (auto [i, x]: history)
      for (i+=1; i<MX; i+=i&-i) bit[i] -= x;
    history.clear();
  }
};

////////////////////////////////
int Q;
vector<int> xs;
Fenwick F;

vector<Point> P;
vector<Rect> R;
lld ans[MQ];

// query: [l, r), P: [si, ei), R: [sj, ej)
void dnc(int l, int r, int si, int ei, int sj, int ej) {
  if (l+1 >= r) return;

  int m = (l+r)/2;
  int mi = si, mj = sj;
  while (mi < ei && P[mi].q < m) mi++;
  while (mj < ej && R[mj].q < m) mj++;

  // DnC
  // P, R will be sorted by y in each partition
  dnc(l, m, si, mi, sj, mj);
  dnc(m, r, mi, ei, mj, ej);

  // Rect | Point
  for (int i=mi, j=sj; i<ei; i++) {
    while (j < mj && R[j].y <= P[i].y) {
      F.add(R[j].l, R[j].v);
      F.add(R[j].r, -R[j].v);
      j++;
    }
    ans[P[i].q] += F.sum(P[i].x);
  }
  F.reset();

  // Point | Rect
  for (int i=si, j=mj; j<ej; j++) {
    while (i < mi && P[i].y < R[j].y) {
      F.add(P[i].x, 1);
      i++;
    }
    ans[R[j].q] += -R[j].v * (F.sum(R[j].r-1) - F.sum(R[j].l-1));
  }
  F.reset();

  // Sort by y
  sort(P.begin()+si, P.begin()+ei, [](Point a, Point b) { return a.y < b.y; });
  sort(R.begin()+sj, R.begin()+ej, [](Rect a, Rect b) { return a.y < b.y; });
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> Q;
  for (int q=0; q<Q; q++) {
    int t, x, y, z, w; cin >> t;
    if (t == 1) {
      cin >> x >> y;
      P.push_back({q, x, y});
      xs.push_back(x);
    } else {
      cin >> x >> y >> z >> w;
      R.push_back({q, x, z+1, y, 1});
      R.push_back({q, x, z+1, w+1, -1});
      xs.push_back(x);
      xs.push_back(z+1);
    }
  }

  // compress
  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());
  for (auto &[q, x, y]: P) {
    x = lower_bound(all(xs), x) - xs.begin();
  }
  for (auto &[q, l, r, y, v]: R) {
    l = lower_bound(all(xs), l) - xs.begin();
    r = lower_bound(all(xs), r) - xs.begin();
  }

  // dnc
  dnc(0, Q, 0, sz(P), 0, sz(R));

  for (int q=0; q<Q; q++) {
    if (q > 0) ans[q] += ans[q-1];
    cout << ans[q] << endl;
  }

  ////////////////////////////////
  return 0;
}
