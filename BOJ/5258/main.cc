#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MOD = 30013;
const int MN = 101010;
const int ST = 1<<18;
int N;

struct Event {
  int x, y, t, i;
  bool operator <(const Event &e) const { return x < e.x; }
};
vector<Event> events;

struct Node {
  int mx, cnt;
  Node operator +(Node &x) {
    Node y = {0, 0};
    y.mx = max(mx, x.mx);
    if (mx >= x.mx) y.cnt += cnt;
    if (mx <= x.mx) y.cnt += x.cnt;
    y.cnt %= MOD;
    return y;
  }
};
Node seg[ST*2], D[MN];

void update(int i, Node x) {
  seg[i += ST] = x;
  for (i/=2; i>0; i/=2) seg[i] = seg[i*2] + seg[i*2+1];
}

Node query(int l, int r) {
  Node ans = {0, 1};
  for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
    if (l&1) ans = ans + seg[l++];
    if (r&1) ans = ans + seg[--r];
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  vector<int> xs;
  for (int i=0; i<N; i++) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    events.push_back({a, c, 1, i});
    events.push_back({b, d, 0, i});
    xs.push_back(c);
    xs.push_back(d);
  }
  sort(events.begin(), events.end());
  sort(xs.begin(), xs.end());
  for (int i=0; i<N*2; i++) {
    events[i].y = lower_bound(xs.begin(), xs.end(), events[i].y) - xs.begin();
  }

  for (auto [x, y, t, i]: events) {
    if (t) { D[i] = query(0, y-1); D[i].mx++; }
    else update(y, D[i]);
  }

  Node ans = query(0, N*2);
  cout << ans.mx << " " << ans.cnt << endl;

  ////////////////////////////////
  return 0;
}
