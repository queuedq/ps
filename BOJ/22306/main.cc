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
int N, Q, par[MN], color[MN], comp[MN];
int cn;
set<int> adj[MN];
map<int, int> S[MN];

void add_color(int comp, int color) {
  S[comp][color]++;
}

void remove_color(int comp, int color) {
  if (--S[comp][color] == 0) S[comp].erase(color);
}

struct Iter {
  int p, u;
  set<int>::iterator it;
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> Q;
  for (int u=2; u<=N; u++) {
    cin >> par[u];
    adj[u].insert(par[u]);
    adj[par[u]].insert(u);
  }
  for (int u=1; u<=N; u++) {
    cin >> color[u];
    add_color(0, color[u]);
  }

  for (int q=1, t, k, ans=0; q<=N+Q-1; q++) {
    cin >> t >> k; k ^= ans;

    if (t == 2) {
      ans = sz(S[comp[k]]);
      cout << ans << endl;
      continue;
    }

    // erase
    int a = k, b = par[k];
    adj[a].erase(b), adj[b].erase(a);

    // parallel dfs
    vector<Iter> stk[2];
    vector<int> vst[2] = {{a}, {b}};
    if (sz(adj[a])) stk[0] = {{0, a, adj[a].begin()}};
    if (sz(adj[b])) stk[1] = {{0, b, adj[b].begin()}};

    while (sz(stk[0]) && sz(stk[1])) {
      for (int i=0; i<2; i++) {
        auto [p, u, it] = stk[i].back(); stk[i].pop_back();
        int v = *it;

        if (++it != adj[u].end()) stk[i].push_back({p, u, it}); // loop
        if (v != p) { // recurse
          vst[i].push_back(v);
          stk[i].push_back({u, v, adj[v].begin()});
        }
      }
    }

    // regroup small comp
    int c0 = comp[a]; cn++;
    auto nodes = sz(stk[0]) == 0 ? vst[0] : vst[1];
    for (auto u: nodes) {
      comp[u] = cn;
      add_color(cn, color[u]);
      remove_color(c0, color[u]);
    }
  }

  ////////////////////////////////
  return 0;
}
