#include <bits/stdc++.h>
#include <iostream>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
int N, A[MN], B[MN], C[MN];
vector<int> adj[MN];
uint64_t H[MN]; // random hashes
bool cut[MN];

uint64_t dfs1(int u, int p) { // find cut edges
  uint64_t h = H[A[u]] + H[B[u]] - H[C[u]] * 2;
  for (int v: adj[u]) {
    if (v == p) continue;
    h += dfs1(v, u);
  }
  cut[u] = h == 0;
  return h;
}

pii dfs2(int u, int p, int limit) { // find max blocks
  int blocks = 0, remain = 1;

  for (int v: adj[u]) {
    if (v == p) continue;
    auto [b, r] = dfs2(v, u, limit);
    blocks += b, remain += r;
  }

  if (cut[u] && remain >= limit) blocks++, remain = 0;
  return {blocks, remain};
}

void solve() {
  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int i=1; i<=N; i++) cin >> B[i];
  for (int i=1; i<=N; i++) cin >> C[i];
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs1(1, 0);

  int l=0, r=N+1;
  while (l+1 < r) {
    int m = (l+r)/2;
    auto [blocks, remain] = dfs2(1, 0, m);
    if (blocks >= 3) l = m;
    else r = m;
  }

  if (l == 0) cout << -1 << endl;
  else cout << l << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  // generate hashes
  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<uint64_t> dist;
  for (int i=0; i<MN; i++) H[i] = dist(mt);

  // solve
  int T; cin >> T;
  while (T--) {
    solve();

    // reset
    for (int i=1; i<=N; i++) adj[i].clear();
  }

  ////////////////////////////////
  return 0;
}
