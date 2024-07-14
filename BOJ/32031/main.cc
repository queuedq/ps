#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MH = 202;
const int MV = MH * MH * 8;
int H, W, vst[MV];
char A[MH][MH];
vector<int> adj[MV];

void add_edge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void dfs(int u) {
  if (vst[u]) return;
  vst[u] = 1;
  for (auto v: adj[u]) dfs(v);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  // top | bot
  // 0 1 | 4 5
  // 2 3 | 6 7

  cin >> H >> W;
  
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      int u = (i*W + j) * 8;
      char c; cin >> c;

      int b;
      if (c == 'H') b = 1;
      else if (c == 'I') b = 2;
      else if (c == 'O') b = 4;

      for (int k=0; k<8; k++) adj[u+k].push_back(u+(k^b));
    }
  }

  for (int i=0; i<H; i++) {
    for (int j=0; j<W-1; j++) {
      int u = (i*W + j) * 8;
      int v = (i*W + (j+1)) * 8;
      add_edge(u+1, v+0), add_edge(u+3, v+2), add_edge(u+5, v+4), add_edge(u+7, v+6);
    }
  }

  for (int i=0; i<H-1; i++) {
    for (int j=0; j<W; j++) {
      int u = (i*W + j) * 8;
      int v = ((i+1)*W + j) * 8;
      add_edge(u+2, v+0), add_edge(u+3, v+1), add_edge(u+6, v+4), add_edge(u+7, v+5);
    }
  }

  int ans = 0;
  for (int u=0; u<H*W*8; u++) {
    if (vst[u]) continue;
    dfs(u);
    ans++;
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
