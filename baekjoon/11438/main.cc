#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, M;
vector<int> adj[MAXN];
int depth[MAXN];
int anc[20][MAXN];

void dfs(int u, int p, int d) {
  depth[u] = d;
  for (auto v: adj[u]) {
    if (v == p) continue;
    anc[0][v] = u;
    dfs(v, u, d+1);
  }
}

int query(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);
  int diff = depth[a] - depth[b];
  for (int i = 0; diff > 0; i++, diff /= 2) {
    if (diff & 1) a = anc[i][a];
  }
  if (a == b) return a;
  for (int i=19; i>=0; i--) {
    if (anc[i][a] != anc[i][b]) {
      a = anc[i][a];
      b = anc[i][b];
    }
  }
  return anc[0][a];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1, 0, 0);

  for (int i=1; i<20; i++) {
    for (int u=1; u<=N; u++) {
      anc[i][u] = anc[i-1][anc[i-1][u]];
    }
  }

  cin >> M;
  for (int i=0; i<M; i++) {
    int a, b; cin >> a >> b;
    cout << query(a, b) << endl;
  }

  ////////////////////////////////
  return 0;
}
