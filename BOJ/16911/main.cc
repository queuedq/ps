#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<17;
int N, M, par[ST], sz[ST], ans[ST];
pii qry[ST];
vector<pii> seg[ST*2], history;

void update(int l, int r, pii e) {
  for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
    if (l&1) seg[l++].push_back(e);
    if (r&1) seg[--r].push_back(e);
  }
}

int find(int x) {
  if (par[x] == x) return x;
  return find(par[x]);
}

void merge(int x, int y) {
  x = find(x); y = find(y);
  if (x == y) return;
  if (sz[x] < sz[y]) swap(x, y);
  history.push_back({x, y});
  par[y] = x;
  sz[x] += sz[y];
}

void rollback() {
  auto [x, y] = history.back();
  history.pop_back();
  sz[x] -= sz[y];
  par[y] = y;
}

void solve(int n, int l, int r) {
  // merge
  int t = history.size();
  for (auto [a, b]: seg[n]) merge(a, b);

  // recurse
  if (n < ST) {
    int m = (l+r) / 2;
    solve(n*2, l, m);
    solve(n*2+1, m, r);
  } else {
    auto [a, b] = qry[l];
    if (a != 0) ans[l] = find(a) == find(b);
  }

  // rollback
  while ((int)history.size() > t) rollback();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  // input
  cin >> N >> M;
  
  map<pii, int> time;
  for (int i=1; i<=M; i++) {
    int q, a, b; cin >> q >> a >> b;
    tie(a, b) = pair(min(a, b), max(a, b));
    if (q == 1) time[{a, b}] = i;
    if (q == 2) { update(time[{a, b}], i, {a, b}); time[{a, b}] = 0; }
    if (q == 3) qry[i] = {a, b};
  }
  for (auto [e, t]: time) {
    if (t == 0) continue;
    auto [a, b] = e;
    update(t, M+1, {a, b});
  }

  // solve
  for (int i=1; i<=N; i++) { par[i] = i; sz[i] = 1; }
  solve(1, 0, ST);

  for (int i=1; i<=M; i++) {
    if (qry[i].first != 0) cout << ans[i] << endl;
  }

  ////////////////////////////////
  return 0;
}
