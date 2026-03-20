#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 305;
int N, M, S, T, Q, dst[MN][MN];
vector<pii> adj[MN];
vector<int> ans;

bool ok(int s, int t) {
  return dst[s][t] != INT_MAX;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> S >> T;
  for (int i=0; i<M; i++) {
    int a, b, c; cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }

  for (int s=1; s<=N; s++) {
    fill(dst[s], dst[s]+N+1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({dst[s][s] = 0, s});

    while (!pq.empty()) {
      auto [d, u] = pq.top(); pq.pop();
      for (auto [v, w]: adj[u]) {
        if (d+w < dst[s][v]) pq.push({dst[s][v] = d+w, v});
      }
    }
  }

  cin >> Q;
  for (int i=0; i<Q; i++) {
    int a, b, c, x, y, z; cin >> a >> b >> c >> x >> y >> z;
    
    int d = dst[S][T];
    if (ok(S, a) && ok(b, T)) d = min(d, dst[S][a] + c + dst[b][T]);
    if (ok(S, x) && ok(y, T)) d = min(d, dst[S][x] + z + dst[y][T]);
    if (ok(S, a) && ok(b, x) && ok(y, T)) d = min(d, dst[S][a] + c + dst[b][x] + z + dst[y][T]);
    if (ok(S, x) && ok(y, a) && ok(b, T)) d = min(d, dst[S][x] + z + dst[y][a] + c + dst[b][T]);
    ans.push_back(d);
  }

  for (auto d: ans) {
    cout << (d == INT_MAX ? -1 : d) << endl;
  }

  ////////////////////////////////
  return 0;
}
