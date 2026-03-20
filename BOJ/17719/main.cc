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
const int MX = 5e5+5;
int N, A, B, C, D, E;
vector<int> adj[MX];
lld dst[3][MX]; // from A, B, C

lld dijkstra(int k, int s) {
  fill_n(dst[k], E+1, INF);
  
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  pq.push({dst[k][s] = 0, s});

  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d > dst[k][u]) continue;

    for (auto v: adj[u]) {
      int w = abs(u-v);
      if (d+w < dst[k][v]) pq.push({dst[k][v] = d+w, v});
    }
  }

  return INF;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> A >> B >> C >> D >> E;
  B += A; C += B; D += C; E += D; // prefix sum

  cin >> N;
  for (int i=0; i<N; i++) {
    int l, r; cin >> l >> r;
    l--;
    adj[l].push_back(r);
    adj[r].push_back(l);
  }

  int Ak = 0, Bk = 1, Ck = 2;
  dijkstra(Ak, A);
  dijkstra(Bk, B);
  dijkstra(Ck, C);

  lld ans = INF;
  ans = min(ans, dst[Ak][B] + dst[Ck][D]); // A-B, C-D
  ans = min(ans, dst[Ak][C] + dst[Bk][D]); // A-C, B-D
  ans = min(ans, dst[Ak][D] + dst[Bk][C]); // A-D, B-C

  if (ans == INF) cout << -1 << endl;
  else cout << ans << endl;

  ////////////////////////////////
  return 0;
}
