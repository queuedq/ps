#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
struct DSU {
  vector<lld> parent, size, l, r;

  DSU(lld s) {
    parent.resize(s); size.resize(s); l.resize(s); r.resize(s);
    for (lld i = 0; i < s; i++) {
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
    cout << x << " " << size[x] << " " << l[x] << " " << r[x] << endl;
  }
} dsu(300'005);

////////////////////////////////
const int MAXN = 3e5+5;
lld N, A[MAXN], L, R;
vector<pll> B, range;
bool vst[MAXN];

lld cnt(lld i, lld x) {
  auto [l, r] = range[i];
  return 1; // TODO: Fix this
}

lld total(lld x) {
  lld ret = 0;
  for (int i=0; i<N; i++) ret += cnt(i, x);
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  cin >> L >> R;

  for (int i=1; i<=N; i++) B.push_back({A[i], i});
  sort(B.rbegin(), B.rend());

  for (int i=0; i<N; i++) {
    cout << B[i].first << " " << B[i].second << endl;
  }

  DSU dsu(N+5);
  for (int i=0; i<=N; i++) {
    auto [a, idx] = B[i];
    vst[idx] = true;
    if (vst[idx-1]) dsu.merge(idx, idx-1);
    if (vst[idx+1]) dsu.merge(idx, idx+1);
    range.push_back({idx - dsu.l[dsu.find(idx)], dsu.r[dsu.find(idx)] - idx});
  }

  lld l = 0, r = N*N;
  while (l+1 < r) {
    lld mid = (l+r)/2;
    if (total(mid) > L) {
      // TODO
    }
  }

  for (int i=0; i<N; i++) {
    cout << range[i].first << " " << range[i].second << endl;
  }

  ////////////////////////////////
  return 0;
}
