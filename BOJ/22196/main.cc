#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 50505;
int N, K, lsb[1<<10], pcnt[1<<10];
set<int> adj[MN];

int clique(int n, vector<int> &G) {
  vector<int> ok(1<<n);
  ok[0] = 1;
  int ans = 0;

  for (int b=1; b<1<<n; b++) {
    int u = lsb[b];
    int s = b - (1<<u);
    ok[b] = ok[s] && (G[u] & s) == s;
    if (ok[b]) ans = max(ans, pcnt[b]);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  // precompute
  for (int b=0; b<1<<10; b++)
    for (int i=9; i>=0; i--)
      if (b>>i & 1) lsb[b] = i, pcnt[b]++;

  // solve
  cin >> N >> K;
  for (int u=0; u<N; u++) {
    int d; cin >> d;
    for (int j=0; j<d; j++) {
      int v; cin >> v;
      adj[u].insert(v);
    }
  }

  set<pii> S;
  for (int u=0; u<N; u++) S.insert({sz(adj[u]), u});

  int ans = 0;
  for (int i=0; i<N; i++) {
    // find smallest deg
    auto [d, u] = *S.begin();

    // build graph
    vector<int> V(adj[u].begin(), adj[u].end());
    vector<int> G(d);
    for (int i=0; i<d; i++)
      for (int j=0; j<d; j++)
        if (adj[V[i]].count(V[j]))
          G[i] |= 1<<j;

    // find clique
    ans = max(ans, clique(d, G) + 1);

    // remove u
    S.erase({d, u});
    for (auto v: V) {
      int d = sz(adj[v]);
      adj[v].erase(u);
      S.erase({d, v});
      S.insert({d-1, v});
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
