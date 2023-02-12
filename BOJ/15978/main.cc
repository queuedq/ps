#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
int N1, N2, K, root[2], par[MN], siz[MN];
vector<int> tree[2][MN];

struct Node { int k, u, cnt, rep; };
Node node[2][MN];

int find(int x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}

void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  if (siz[x] < siz[y]) swap(x, y);
  par[y] = x;
  siz[x] += siz[y];
}

void dfs(int k, int u) {
  node[k][u] = {k, u, u <= K, u};
  for (int v: tree[k][u]) {
    dfs(k, v);
    node[k][u].cnt += node[k][v].cnt;
    node[k][u].rep = node[k][v].rep;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N1 >> N2 >> K;
  for (int i=1; i<=K; i++) par[i] = i, siz[i] = 1;

  for (int i=1; i<=N1; i++) {
    int p; cin >> p;
    if (p == 0) root[0] = i;
    else tree[0][p].push_back(i);
  }
  for (int i=1; i<=N2; i++) {
    int p; cin >> p;
    if (p == 0) root[1] = i;
    else tree[1][p].push_back(i);
  }

  dfs(0, root[0]);
  dfs(1, root[1]);

  vector<Node> E;
  for (int i=K+1; i<=N1; i++) if (sz(tree[0][i]) > 1) E.push_back(node[0][i]);
  for (int i=K+1; i<=N2; i++) if (sz(tree[1][i]) > 1) E.push_back(node[1][i]);
  sort(all(E), [](Node a, Node b) { return a.cnt < b.cnt; });

  bool ok = 1;
  for (auto [k, u, cnt, rep]: E) {
    for (auto v: tree[k][u]) merge(rep, node[k][v].rep);
    if (node[k][u].cnt != siz[find(rep)]) { ok = 0; break; }
  }

  cout << (ok ? "YES" : "NO") << endl;

  ////////////////////////////////
  return 0;
}
