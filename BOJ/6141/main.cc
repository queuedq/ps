#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
lld N, M, A[MN], inQ[MN], cycle[MN];
double dst[MN];
vector<pii> adj[MN];

bool spfa(double avg) { // false when negative cycle detected
  fill(dst+1, dst+N+1, 0);
  fill(inQ+1, inQ+N+1, 1);
  fill(cycle+1, cycle+N+1, 0);

  queue<int> Q;
  for (int u=1; u<=N; u++) Q.push(u);
  
  while (!Q.empty()) {
    int u = Q.front(); Q.pop(); inQ[u] = 0;

    for (auto [v, t]: adj[u]) {
      double c = t * avg - A[u];
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
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int i=0; i<M; i++) {
    int u, v, t; cin >> u >> v >> t;
    adj[u].push_back({v, t});
  }

  double l=-0.1, r=1000.1;
  while (l+1e-5 < r) {
    double m = (l+r)/2;
    if (!spfa(m)) l = m;
    else r = m;
  }

  if (l < 0) {
    cout << 0 << endl;
  } else {
    cout << fixed << setprecision(2) << l << endl;
  }

  ////////////////////////////////
  return 0;
}
