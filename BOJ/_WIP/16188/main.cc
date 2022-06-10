#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
struct DSU {
  vector<lld> parent, size, l, r;

  DSU(lld sz) {
    parent.resize(sz); size.resize(sz); l.resize(sz); r.resize(sz);
    for (lld i = 0; i < sz; i++) {
      parent[i] = l[i] = r[i] = i;
      size[i] = 1;
    }
  }

  lld find(lld x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
  }

  void merge(lld x, lld y) {
    x = find(x); y = find(y);
    if (size[x] < size[y]) swap(x, y);
    parent[y] = x;
    size[x] += size[y];
    l[x] = min(l[x], l[y]);
    r[x] = max(r[x], r[y]);
  }
};

////////////////////////////////
const int MAXN = 3e5+5;
lld N, L, R;
vector<pll> A;
vector<lld> hs;
bool vst[MAXN];

lld sum(lld s, lld e) { return (s+e)*(e-s+1)/2; }

lld cnt_width(lld W, lld mw) {
  // number of itv of width <= mw contained in itv of width W
  lld ret = W * (W+1) / 2;
  if (mw <= W) ret -= (W-mw) * (W-mw+1) / 2;
  return ret;
}

lld cnt_area(lld area) { // number of rect <= area
  lld ret = 0, i = 0;
  for (auto h: hs) {
    lld mw = area/h; // max width
    int x = 0;
    ret += cnt_width(N, mw); // TODO: fix
    for (; i<N && A[i].first == h; i++) {
      ret -= cnt_width(A[i].second, mw);
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    lld h; cin >> h;
    A.push_back({h, i});
    hs.push_back(h);
  }
  cin >> L >> R;

  // Sort by decreasing height
  sort(all(A));
  sort(all(hs));
  hs.erase(unique(all(hs)), hs.end());

  // Find Lth area
  // total(s) < L <= total(e), e is Lth area
  lld s = 0, e = N*1e9;
  while (s+1 < e) {
    lld mid = (s+e)/2;
    if (total(mid) >= L) e = mid;
    else s = mid;
  }
  lld t = total(e-1);

  // Sweep from Lth area to Rth area
  vector<lld> ans;
  priority_queue<pll, vector<pll>, greater<pll>> pq; // {area, bucket_idx}
  for (int i=0; i<N; i++) {
    auto [h, _] = A[i];
    if (e % h == 0) pq.push({e, i});
    else pq.push({(e/h+1) * h, i});
  }

  while (!pq.empty() && ans.size() < R - t) {
    auto [area, i] = pq.top(); pq.pop();
    auto [h, _] = A[i];
    lld w = area / h;
    for (int j = cnt(i, w); j > 0; j--) ans.push_back(area);
    if (cnt(i, w+1) > 0) pq.push({(w+1) * h, i});
  }

  for (int i=L; i<=R; i++) {
    while (i-t-1 < 0 || i-t-1 >= ans.size()) cout << 1;
    cout << ans[i-t-1] << endl;
  }

  ////////////////////////////////
  return 0;
}
