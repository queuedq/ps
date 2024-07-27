#include <bits/stdc++.h>
using namespace std;
using lld = long long;

const int MN = 101010;
lld N, D[MN];
vector<int> adj[MN];

lld dp(int u, int p) {
  D[u] = u;

  lld op = LLONG_MAX;
  for (auto v: adj[u]) {
    if (v == p) continue;
    op = min(op, dp(v, u));
  }

  if (op < LLONG_MAX) D[u] -= op;
  return D[u];
}

int main() {
  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dp(1, 0);
  for (int i=1; i<=N; i++) cout << (D[i] >= 0) << endl;
  return 0;
}
