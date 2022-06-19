#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
int N, M, vst[MN], D[MN];
char S[MN];
vector<int> adj[MN];

int char_idx(char c) {
  if (c == 'K') return 0;
  if (c == 'D') return 1;
  if (c == 'H') return 2;
  return -1;
}

void make_edge(int u, int v) {
  int a = char_idx(S[u]);
  int b = char_idx(S[v]);
  if (a+1 == b || a-2 == b) adj[u].push_back(v);
  if (b+1 == a || b-2 == a) adj[v].push_back(u);
}

bool dfs(int u) { // true if cyclic
  vst[u] = 1;
  for (int v: adj[u]) {
    if (vst[v] == 1) return 1;
    if (vst[v] == 0) {
      if (dfs(v)) return 1;
    }
    D[u] = max(D[u], D[v]+1);
  }
  vst[u] = 2;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) cin >> S[i];
  for (int i=0; i<M; i++) { int u, v; cin >> u >> v; make_edge(u, v); }
  
  for (int i=1; i<=N; i++) {
    if (S[i] == 'K') adj[0].push_back(i);
  }

  bool cyc = dfs(0);
  if (cyc || D[0] < 3) cout << -1 << endl;
  else cout << D[0] - D[0]%3 << endl;

  ////////////////////////////////
  return 0;
}
