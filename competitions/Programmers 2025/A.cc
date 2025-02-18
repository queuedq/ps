#include <bits/stdc++.h>
#define sz(x) int(x.size())
using namespace std;
using lld = long long;
using pii = pair<int, int>;

////////////////////////////////////////////////////////////////
const int MX = 404040;
vector<int> adj[MX];
int vst[MX];

vector<int> chain;
map<int, int> used;

void dfs(int u, int p) {
  if (vst[u]) return;
  vst[u] = 1;
  chain.push_back(u);

  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
}

int max_len() {
  int N = sz(chain);
  int len = 0;

  for (int i=0, j=0; i<N; i++) {
    while (used[chain[i]/2]) { used[chain[j]/2] = 0; j++; }
    used[chain[i]/2] = 1;
    len = max(len, i-j+1);
  }
  return len;
}

int solution(vector<vector<int>> G) {
  // G = 1: [0/1]
  // G = -1: [1\0]
  int N = sz(G), M = sz(G[0]);

  // vertical
  for (int i=0; i<N-1; i++) {
    for (int j=0; j<M; j++) {
      // (i, j), (i+1, j)
      int a = (i*M + j) * 2 + 1;
      int b = ((i+1)*M + j) * 2;
      // cout << a << "|" << b << endl;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
  }

  // horizontal
  for (int i=0; i<N; i++) {
    for (int j=0; j<M-1; j++) {
      // (i, j), (i, j+1)
      int a = (i*M + j) * 2 + (G[i][j] == 1);
      int b = (i*M + (j+1)) * 2 + (G[i][j+1] == -1);
      // cout << a << "-" << b << endl;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
  }

  int ans = 1;

  // chains
  for (int u=0; u<N*M*2; u++) {
    if (sz(adj[u]) == 1) {
      chain.clear();
      used.clear();
      dfs(u, -1);

      int len = max_len();
      ans = max(ans, len);

      // for (auto c: chain) cout << c << " ";
      // cout << ": " << len << endl;
    }
  }

  // loops
  for (int u=0; u<N*M*2; u++) {
    if (sz(adj[u]) == 2) {
      chain.clear();
      used.clear();
      dfs(u, -1);

      int c = sz(chain);
      for (int i=0; i<c; i++) chain.push_back(chain[i]);
      int len = max_len();
      ans = max(ans, len);

      // for (auto c: chain) cout << c << " ";
      // cout << ": " << len << endl;
    }
  }

  return ans;
}
