#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 1e18;
const lld MX = 1<<20;
const lld MASK = MX - 1;
lld N, x, y, t;
vector<lld> adj[MX+1];

lld dist(lld s, lld e, lld g) {
  queue<lld> Q;
  vector<lld> dist(MX+1, INF);
  dist[s] = 0;
  Q.push(s);

  while (!Q.empty()) {
    lld u = Q.front(); Q.pop();
    if ((g<<20) + u >= N) continue; // OOB
    if (u == e) return dist[u];

    for (lld v: adj[u]) {
      if (dist[v] < INF) continue;
      dist[v] = dist[u] + 1;
      Q.push(v);
    }
  }
  return INF;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> x >> y >> t;

  for (lld u=0; u<MX; u++) {
    adj[u].push_back(u^t);
    adj[u].push_back((u^t) + 1);
  }

  lld xg = x >> 20, yg = y >> 20;
  lld jumps = yg - xg;

  // cannot reach smaller group
  if (jumps < 0) {
    cout << -1 << endl;
    return 0;
  }

  // same group
  if (jumps == 0) {
    lld ans = dist(x & MASK, y & MASK, xg);
    cout << (ans < INF ? ans : -1) << endl;
    return 0;
  }

  // larger group
  lld a = dist(x & MASK, MX, xg);
  lld b = dist(0, MX, xg);
  lld c = dist(0, y & MASK, yg);

  if (max({a, b, c}) == INF) {
    cout << -1 << endl;
    return 0;
  }

  lld ans = a + b * (jumps - 1) + c;
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
