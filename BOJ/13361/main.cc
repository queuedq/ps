#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 500'000;
int N, par[MN], sz[MN], edge[MN], mx[MN];
pii A[MN];
vector<int> xs;

int find(int x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  edge[x]++;
  if (x == y) return;
  par[y] = x;
  sz[x] += sz[y];
  edge[x] += edge[y];
  mx[x] = max(mx[x], mx[y]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int s, t; cin >> s >> t;
    A[i] = {s, t};
    xs.push_back(s);
    xs.push_back(t);
  }

  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());

  iota(par, par+xs.size(), 0);
  fill(sz, sz+xs.size(), 1);
  iota(mx, mx+xs.size(), 0);

  for (int i=0; i<N; i++) {
    int a = lower_bound(xs.begin(), xs.end(), A[i].first) - xs.begin();
    int b = lower_bound(xs.begin(), xs.end(), A[i].second) - xs.begin();
    merge(a, b);
  }

  lld ans = 0;
  for (int i=0; i<N; i++) ans += A[i].first + A[i].second;
  for (int i=0; i<xs.size(); i++) ans -= xs[i];

  for (int i=0; i<xs.size(); i++) {
    if (i != par[i]) continue;
    assert(edge[i] <= sz[i]);
    if (edge[i] < sz[i]) ans += xs[mx[i]];
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
