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
int N, a, b, c, f;
vector<int> adj[MN];
int par[MN], ord[MN], dfn, H[MN];
int vst[MN];

void dfs(int u, int p) {
  par[u] = p;
  ord[u] = ++dfn;
  H[u] = 0;
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    H[u] = max(H[u], H[v]+1);
  }
}

void reach(int u, int p) {
  vst[u] = 1;
  for (auto v: adj[u]) {
    if (v == p) continue;
    reach(v, u);
  }
}

void solve() {
  cin >> N;
  for (int u=2; u<=N; u++) {
    int v; cin >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cin >> a >> b >> c >> f;

  // find center of three points
  dfn = 0, dfs(a, 0);
  if (ord[b] > ord[c]) swap(b, c);
  int r = c;
  while (ord[b] < ord[r]) r = par[r];

  // change root
  dfn = 0, dfs(r, 0);

  // find highest leg positions
  int sum = H[a] + H[b] + H[c];
  while (true) {
    int prv = sum;
    while (a != r && H[a] < sum) { sum += H[par[a]] - H[a] - 1; a = par[a]; }
    while (b != r && H[b] < sum) { sum += H[par[b]] - H[b] - 1; b = par[b]; }
    while (c != r && H[c] < sum) { sum += H[par[c]] - H[c] - 1; c = par[c]; }
    if (a == r || b == r || c == r || prv == sum) break;
  }

  // check reachability
  fill_n(vst, N+1, 0);
  reach(a, par[a]);
  reach(b, par[b]);
  reach(c, par[c]);

  cout << (vst[f] ? "Yes" : "No") << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    solve();
    for (int u=1; u<=N; u++) adj[u].clear();
  }

  ////////////////////////////////
  return 0;
}
