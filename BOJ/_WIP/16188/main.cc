#include <bits/stdc++.h>
#define endl "\n"
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
vector<pll> A, range;
bool vst[MAXN];

lld sum(lld s, lld e) { return (s+e)*(e-s+1)/2; }

// Number of rectangles with width = w in ith bucket
lld cnt(lld i, lld w) {
  auto [l, r] = range[i];
  l = min(l, w-1); r = min(r, w-1);
  return max(0LL, r - (w-l-1) + 1);
}

// Number of rectangles with width <= w in ith bucket
lld cntSum(lld i, lld w) {
  auto [l, r] = range[i];
  l = min(l, w-1); r = min(r, w-1);
  if (w-l-1 <= r) return sum(w-l, r+1) + (r+1)*(w-r-1);
  return (r+1)*(l+1);
}

lld total(lld area) {
  lld ret = 0;
  for (int i=0; i<N; i++) ret += cntSum(i, area/A[i].first);
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
  }
  cin >> L >> R;

  // Sort by decreasing height
  sort(A.rbegin(), A.rend());

  // Find width ranges per bucket
  // range {l, r}: width can extend l units left and r units right
  DSU dsu(N+5);
  for (int i=0; i<N; i++) {
    auto [h, j] = A[i];
    vst[j] = true;
    if (vst[j-1]) dsu.merge(j, j-1);
    if (vst[j+1]) dsu.merge(j, j+1);
    range.push_back({
      j - dsu.l[dsu.find(j)],
      dsu.r[dsu.find(j)] - j
    });
  }

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
