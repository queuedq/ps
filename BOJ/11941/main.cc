#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 1e15;
const int MX = 1<<17;
lld M, N, L[MX*2], R[MX*2];
vector<lld> xs;

struct Hopper { int a, b, c, d; };
Hopper A[MX];

void upd(lld seg[], int i, lld v) {
  i += MX;
  seg[i] = min(seg[i], v);
  for (i /= 2; i > 0; i /= 2) seg[i] = min(seg[i*2], seg[i*2+1]);
}

lld qry(lld seg[], int l, int r) {
  lld res = LLONG_MAX;
  for (l += MX, r += MX+1; l < r; l /= 2, r /= 2) {
    if (l&1) res = min(res, seg[l++]);
    if (r&1) res = min(res, seg[--r]);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> M >> N;
  xs = {1, N};

  for (int i=0; i<M; i++) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    xs.push_back(c);
    A[i] = {a, b, c, d};
  }
  
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());

  for (int i=0; i<M; i++) {
    A[i].a = lower_bound(xs.begin(), xs.end(), A[i].a) - xs.begin();
    A[i].b = upper_bound(xs.begin(), xs.end(), A[i].b) - xs.begin() - 1;
    A[i].c = lower_bound(xs.begin(), xs.end(), A[i].c) - xs.begin();
  }

  fill(L, L+MX*2, INF);
  fill(R, R+MX*2, INF);
  upd(L, 0, 0);
  upd(R, xs.size()-1, 0);

  lld ans = INF;
  for (int i=0; i<M; i++) {
    lld lm = qry(L, A[i].a, A[i].b);
    lld rm = qry(R, A[i].a, A[i].b);
    ans = min(ans, lm + rm + A[i].d);
    upd(L, A[i].c, lm + A[i].d);
    upd(R, A[i].c, rm + A[i].d);
  }

  if (ans == INF) cout << -1 << endl;
  else cout << ans << endl;

  ////////////////////////////////
  return 0;
}
