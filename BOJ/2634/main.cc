#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505;
int N;
vector<int> adj[MN], path[MN];
pii D[MN]; // open path (len, leaf) at u
int match[MN]; // matched paths

bool dfs(int u, int p, int mx) {
  set<pii> S;
  if (sz(adj[u]) == 1) S.insert({0, u});
  for (auto v: adj[u]) {
    if (v == p) continue;
    if (!dfs(v, u, mx)) return false;
    auto [d, x] = D[v];
    S.insert({d+1, x});
  }


  // matching
  pii rem = {0, 0};
  while (!S.empty()) {
    // match the longest in S...
    auto it = prev(S.end());
    auto [d, x] = *it;
    S.erase(it);

    // ...with another longest matchable (d+e <= mx)
    it = S.lower_bound({mx-d+1, 0});
    if (it == S.begin()) { // no match
      if (rem.second) return false;
      rem = {d, x};
      continue;
    }
    auto [e, y] = *(--it);
    S.erase(it);

    // update match
    path[x].push_back(u);
    match[x] = y;
  }

  // dp
  if (p != 0) {
    auto [d, x] = rem;
    path[x].push_back(u);
    D[u] = {d, x};
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // check possible
  int ok = 1, lcnt = 0;
  for (int i=1; i<=N; i++) {
    int deg = sz(adj[i]);
    ok &= deg == 1 || deg%2 == 0;
    lcnt += deg == 1;
  }
  if (!ok) { cout << 0 << endl; return 0; }

  // solve
  int l = 0, r = N-1;
  while (l+1 < r) {
    for (int i=1; i<=N; i++) path[i].clear();
    fill(match, match+N+1, 0);

    int m = (l+r)/2;
    if (dfs(1, 0, m)) r = m;
    else l = m;
  }

  // print
  for (int i=1; i<=N; i++) path[i].clear();
  fill(match, match+N+1, 0);
  dfs(1, 0, r);

  cout << r << endl;
  cout << lcnt / 2 << endl;
  for (int x=1, y; x<=N; x++) {
    y = match[x];
    if (y) {
      reverse(all(path[y]));
      for (auto u: path[x]) cout << u << " ";
      for (auto u: path[y]) cout << u << " ";
      cout << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
