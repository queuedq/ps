#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2e5+5;
int N, Q, par[MN], uni[MN], sz[MN];

struct Query { int x, u, v; };
vector<Query> query;
set<int> erased;
vector<bool> ans;

int find(int x) {
  if (x == uni[x]) return x;
  return uni[x] = find(uni[x]);
}

void merge(int x, int y) {
  x = find(x); y = find(y);
  if (x == y) return;
  if (sz[x] < sz[y]) swap(x, y);
  uni[y] = x;
  sz[x] += sz[y];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> Q;
  for (int i=2; i<=N; i++) cin >> par[i];
  for (int i=0; i<N-1+Q; i++) {
    int x, u, v; cin >> x;
    if (x == 0) {
      cin >> u;
      erased.insert(u);
      query.push_back({x, u, 0});
    } else {
      cin >> u >> v;
      query.push_back({x, u, v});
    }
  }

  for (int i=1; i<=N; i++) uni[i] = i;

  for (int i=1; i<=N; i++) {
    if (erased.count(i) == 0) merge(i, par[i]);
  }

  reverse(query.begin(), query.end());
  for (auto [x, u, v]: query) {
    if (x == 0) {
      merge(u, par[u]);
    } else {
      ans.push_back(find(u) == find(v));
    }
  }

  reverse(ans.begin(), ans.end());
  for (auto a: ans) cout << (a ? "YES" : "NO") << endl;

  ////////////////////////////////
  return 0;
}
