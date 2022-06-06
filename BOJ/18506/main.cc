#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
const int MK = 2e3+5; // Note: binom(k,2) <= m
int n, m, k, c, C[MN], cmap[MK], vst[MK], iso[MK];
vector<int> G[MN], T[MK];

void solve() {
  cin >> n >> m >> k;
  for (int i=0; i<m; i++) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int i=0; i<k-1; i++) {
    int u, v; cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }

  int x = 0; // node of color k
  for (int u=1; u<=n; u++) {
    // greedy coloring
    vector<int> used;
    for (auto v: G[u]) {
      if (C[v] != 0) used.push_back(C[v]);
    }
    sort(all(used));
    used.erase(unique(all(used)), used.end());

    for (int c=1; c<=k; c++) {
      if (c-1 >= used.size() || used[c-1] != c) { C[u] = c; break; }
    }

    if (C[u] == k) { x = u; break; }
  }

  c = k;
  queue<int> Q;
  vst[1] = 1, iso[1] = x;
  Q.push(1);

  while (!Q.empty()) {
    int u = Q.front(); Q.pop();
    int x = iso[u];
    for (auto y: G[x]) cmap[C[y]] = y;
    
    for (auto v: T[u]) {
      if (vst[v]) continue;
      vst[v] = 1, iso[v] = cmap[--c];
      Q.push(v);
    }
  }

  cout << "Yes" << endl;
  for (int u=1; u<=k; u++) cout << iso[u] << " ";
  cout << endl;
}

void reset() {
  fill(C, C+n+1, 0);
  fill(vst, vst+k+1, 0);
  for (int i=1; i<=n; i++) G[i].clear();
  for (int i=1; i<=k; i++) T[i].clear();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int t; cin >> t;
  while (t--) {
    solve();
    reset();
  }

  ////////////////////////////////
  return 0;
}
