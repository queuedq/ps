#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 3005;
const int ST = 1<<12;

int N;

struct Mine {
  lld x, y, w;
  bool operator <(const Mine m) const { return x < m.x; }
} mine[MAXN];

struct Node {
  lld l, r, m, s;
} seg[ST*2];

Node merge(Node a, Node b) {
  return {
    max(a.l, a.s+b.l),
    max(b.r, b.s+a.r),
    max({a.m, b.m, a.r+b.l}),
    a.s+b.s
  };
}

Node query(int n, int nl, int nr, int l, int r) {
  if (l <= nl && nr <= r) return seg[n];
  if (nr < l || r < nl) return {0, 0, 0, 0};
  int mid = (nl+nr+1)/2;
  return merge(query(n*2, nl, mid-1, l, r), query(n*2+1, mid, nr, l, r));
}

void update(int i, lld d) {
  int n = ST+i;
  lld w = seg[n].s+d;
  lld m = max(0LL, w);
  seg[n] = {m, m, m, w};
  n /= 2;
  while (n > 0) {
    seg[n] = merge(seg[n*2], seg[n*2+1]);
    n /= 2;
  }
}

void reset() {
  for (int i=0; i<ST*2; i++) seg[i] = {0, 0, 0, 0};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  vector<lld> xcoords, ycoords;
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> mine[i].x >> mine[i].y >> mine[i].w;
    xcoords.push_back(mine[i].x);
    ycoords.push_back(mine[i].y);
  }

  sort(mine, mine+N);
  sort(xcoords.begin(), xcoords.end());
  sort(ycoords.begin(), ycoords.end());

  for (int i=0; i<N; i++) {
    mine[i].x = lower_bound(xcoords.begin(), xcoords.end(), mine[i].x) - xcoords.begin();
    mine[i].y = lower_bound(ycoords.begin(), ycoords.end(), mine[i].y) - ycoords.begin();
  }

  lld ans = 0;
  for (int s=0; s<N; s++) {
    while (s > 0 && mine[s-1].x == mine[s].x) s++;
    reset();

    for (int e=s; e<N; e++) {
      update(mine[e].y, mine[e].w);
      while (e < N-1 && mine[e].x == mine[e+1].x) {
        e++;
        update(mine[e].y, mine[e].w);
      }

      ans = max(ans, query(1, 0, ST-1, 0, N-1).m);
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
