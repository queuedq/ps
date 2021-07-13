#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<15;
int N, seg[ST*2][2];

struct Event {
  int x, t, y1, y2;
  bool operator <(const Event &e) const { return x < e.x; }
};

void update(int n, int nl, int nr, int l, int r, int v) {
  if (r < nl || nr < l) return;
  if (l <= nl && nr <= r) {
    seg[n][0] += v;
  } else {
    int m = (nl+nr+1) / 2;
    update(n*2, nl, m-1, l, r, v);
    update(n*2+1, m, nr, l, r, v);
  }

  if (seg[n][0] != 0) seg[n][1] = nr - nl + 1;
  else seg[n][1] = n < ST ? seg[n*2][1] + seg[n*2+1][1] : 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;

  vector<Event> E;
  for (int i=0; i<N; i++) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    E.push_back({x1, 1, y1, y2});
    E.push_back({x2, -1, y1, y2});
  }
  sort(E.begin(), E.end());

  int ans = 0, x0 = 0;
  for (auto [x, t, y1, y2]: E) {
    ans += (x-x0) * seg[1][1];
    update(1, 0, ST-1, y1, y2-1, t);
    x0 = x;
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
