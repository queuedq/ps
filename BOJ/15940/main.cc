#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N;
vector<pll> adj[MN];
vector<lld> H[MN], D[MN]; // best 3 heights, best 2 diameters of children
lld ans;

void insert(vector<lld> &v, lld x) {
  for (int i=0; i<sz(v); i++) {
    if (x > v[i]) swap(x, v[i]);
  }
}

void erase(vector<lld> &v, lld x) {
  auto it = find(all(v), x);
  if (it != v.end()) v.erase(it);
}

void dfs1(int u, int p) { // initial dp
  H[u] = {0, 0, 0};
  D[u] = {0, 0};

  for (auto [v, w]: adj[u]) {
    if (v == p) continue;
    dfs1(v, u);
    insert(H[u], H[v][0] + w);
    insert(D[u], max(D[v][0], H[v][0] + H[v][1]));
  }
}

void dfs2(int u, int p) {
  auto Hu = H[u], Du = D[u];

  for (auto [v, w]: adj[u]) {
    if (v == p) continue;
    auto Hv = H[v], Dv = D[v];

    // rerooting
    erase(H[u], H[v][0] + w);
    erase(D[u], max(D[v][0], H[v][0] + H[v][1]));

    ans = max(ans, max(D[u][0], H[u][0] + H[u][1]) + max(D[v][0], H[v][0] + H[v][1]) + w);

    insert(H[v], H[u][0] + w);
    insert(D[v], max(D[u][0], H[u][0] + H[u][1]));

    dfs2(v, u);

    // rollback
    H[u] = Hu, H[v] = Hv, D[u] = Du, D[v] = Dv;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  dfs1(1, 0);
  dfs2(1, 0);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
