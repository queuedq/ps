#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505;
const int INF = 1e9;
// 1-based index
// dst should be long long because a negative cycle can overflow it
lld N, M, dst[MN], inQ[MN], cycle[MN];
vector<pii> adj[MN];

bool SPFA(int s) { // returns false if a negative cycle exists
  fill(dst+1, dst+N+1, INF);
  fill(inQ+1, inQ+N+1, 0);
  fill(cycle+1, cycle+N+1, 0);
  dst[s] = 0;

  queue<int> Q; Q.push(s); inQ[s] = 1;
  while (!Q.empty()) {
    int u = Q.front(); Q.pop(); inQ[u] = 0;

    for (auto [v, c]: adj[u]) {
      if (dst[u] + c >= dst[v]) continue;
      dst[v] = dst[u] + c;
      if (!inQ[v]) {
        if (++cycle[v] >= N) return false;
        Q.push(v); inQ[v] = 1;
      }
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int a, b, c; cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }

  bool res = SPFA(1);
  if (!res) { cout << -1 << endl; return 0; }
  for (int i=2; i<=N; i++) {
    if (dst[i] < INF) cout << dst[i] << endl;
    else cout << -1 << endl;
  }

  ////////////////////////////////
  return 0;
}
