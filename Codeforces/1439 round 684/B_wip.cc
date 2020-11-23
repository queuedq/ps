#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;
int N, M, K;
vector<int> adj[MN];
int deg[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }

  queue<int> q;
  for (int i=1; i<=N; i++) {
    if (deg[u] < K) q.push()
  }

  ////////////////////////////////
  return 0;
}
