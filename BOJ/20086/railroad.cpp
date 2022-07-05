#include <bits/stdc++.h>
#include "railroad.h"
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
vector<lld> xs, par;
vector<pll> mst;

struct Event {
  lld x, s; // s: start(1), end(0)
  bool operator <(const Event &E) const { return x < E.x; }
};
vector<Event> E;

int find(int x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}

void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  par[y] = x;
}

int compress(int x) { return lower_bound(all(xs), x) - xs.begin(); }

lld plan_roller_coaster(vector<int> s, vector<int> t) {
  int N = (int)s.size();

  for (int i=0; i<N; i++) {
    E.push_back({s[i], 1}); xs.push_back(s[i]);
    E.push_back({t[i], 0}); xs.push_back(t[i]);
  }
  xs.push_back(1);
  sort(all(E)); sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());

  // merge s[i] - t[i]
  par.resize(xs.size());
  iota(all(par), 0);
  for (int i=0; i<N; i++) merge(compress(s[i]), compress(t[i]));

  // add essential edges
  lld x0 = 1, cnt = -1, ans = 0; // start from auxiliary inf -> 1 section
  for (auto [x, s]: E) {
    ans += (x-x0) * max(cnt, 0LL);

    if (cnt != 0) // merge x0 - x
      merge(compress(x0), compress(x));
    else // will be connected in MST step
      mst.push_back({x0, x});

    x0 = x;
    cnt += (s ? 1 : -1);
  }
  merge(compress(x0), compress(1)); // end at auxiliary inf -> 1 section

  // MST between connected components
  sort(all(mst), [&](pll e, pll f) { return e.second - e.first < f.second - f.first; });
  for (auto [x, y]: mst) {
    int i = compress(x), j = compress(y);
    i = find(i), j = find(j);
    if (i == j) continue;

    ans += y - x;
    merge(i, j);
  }

  return ans;
}
