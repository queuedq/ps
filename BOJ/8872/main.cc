#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, M, L, vst[MN], dst[MN];
vector<pii> adj[MN];

pii farthest(int u, int p, int d) {
  dst[u] = max(dst[u], d);

  pii res = {u, d};
  for (auto [v, w]: adj[u]) {
    if (v == p) continue;
    pii sub = farthest(v, u, d+w);
    if (sub.second > res.second) res = sub;
  }
  return res;
}

int radius(int u, int p) {
  vst[u] = 1;

  int r = dst[u];
  for (auto [v, w]: adj[u]) {
    if (v == p) continue;
    r = min(r, radius(v, u));
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> L;
  for (int i=0; i<M; i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  // diameters & radii
  int ans = 0;
  vector<int> R;
  for (int i=0; i<N; i++) {
    if (vst[i]) continue;
    auto [x, _] = farthest(i, -1, 0);
    auto [y, d] = farthest(x, -1, 0);
    farthest(y, -1, 0);

    ans = max(ans, d);
    R.push_back(radius(i, -1));
  }

  // answer
  sort(all(R));
  reverse(all(R));

  if (sz(R) >= 2) ans = max(ans, R[0]+R[1] + L);
  if (sz(R) >= 3) ans = max(ans, R[1]+R[2] + L*2);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
