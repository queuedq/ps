#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, Q, R, up[MN], par[MN];
vector<int> ans;
unordered_set<int> colors[MN];

struct Query { int t, u; };
vector<Query> qry;

int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

void merge(int x, int y) {
  x = find(x), y = find(y);
  if (sz(colors[x]) < sz(colors[y])) swap(x, y);
  par[y] = x;
  for (auto c: colors[y]) colors[x].insert(c);
  colors[y].clear();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> Q;
  for (int i=2; i<=N; i++) cin >> up[i];
  for (int i=1; i<=N; i++) {
    int c; cin >> c;
    colors[i].insert(c);
  }
  for (int i=0; i<N-1+Q; i++) {
    int t, u; cin >> t >> u;
    qry.push_back({t, u});
  }
  reverse(all(qry));

  iota(par, par+N+1, 0);
  for (auto [t, u]: qry) {
    if (t == 1) merge(u, up[u]);
    else ans.push_back(sz(colors[find(u)]));
  }

  reverse(all(ans));
  for (auto a: ans) cout << a << endl;

  ////////////////////////////////
  return 0;
}
