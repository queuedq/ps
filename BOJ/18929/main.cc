#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int _N = 5e5+5;
int N, adj[_N*2], color[_N*2];

void dfs(int u, int c) {
  if (color[u] != -1) return;
  color[u] = c;
  dfs(adj[u], !c);
  dfs(u^1, !c);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  fill(color, color+N*2, -1);
  for (int i=0; i<N; i++) {
    int a, b; cin >> a >> b; a--; b--;
    adj[a] = b;
    adj[b] = a;
  }

  for (int i=0; i<N*2; i++) dfs(i, 0);
  for (int i=0; i<N*2; i++) cout << "XY"[color[i]];

  ////////////////////////////////
  return 0;
}
