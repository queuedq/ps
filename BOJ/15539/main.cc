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
lld N, g[MN], sub[MN], vst[MN], ans;
vector<pll> adj[MN];

struct Info {
  lld gas, len, r;
  bool operator<(Info I) const { return gas < I.gas; }
};

int get_size(int u, int p) {
  sub[u] = 1;
  for (auto [v, w]: adj[u]) {
    if (v == p || vst[v]) continue;
    sub[u] += get_size(v, u);
  }
  return sub[u];
}

int centroid(int u, int p, int tot) {
  for (auto [v, w]: adj[u]) {
    if (v == p || vst[v]) continue;
    if (sub[v] > tot/2) return centroid(v, u, tot);
  }
  return u;
}

void incoming(int u, int p, lld gas, lld low, int len, int r, vector<Info> &in) {
  if (low == 0) in.push_back({gas, len, r});

  for (auto [v, w]: adj[u]) {
    if (v == p || vst[v]) continue;
    lld dt = g[v] - w;
    incoming(v, u, dt + gas, min(0LL, dt + low), len+1, r, in);
  }
}

void outgoing(int u, int p, lld gas, lld low, int len, int r, vector<Info> &out) {
  out.push_back({-low, len, r});

  for (auto [v, w]: adj[u]) {
    if (v == p || vst[v]) continue;
    lld dt = g[u] - w;
    outgoing(v, u, gas + dt, min(low, gas + dt), len+1, r, out);
  }
}

void solve(int u) {
  int c = centroid(u, 0, get_size(u, 0));
  vst[c] = 1;

  // get in/out paths
  vector<Info> in = {{0, 0, c}}, out = {{0, 0, c}};

  for (auto [v, w]: adj[c]) {
    if (vst[v]) continue;
    incoming(v, c, g[v] - w, min(0LL, g[v] - w), 1, v, in);
    outgoing(v, c, g[c] - w, min(0LL, g[c] - w), 1, v, out);
  }
  sort(all(in));
  sort(all(out));

  // get ans
  int i = 0;
  Info P = {0, 0, c}, Q = {0, 0, c}; // two best out paths

  for (auto [gas, len, r]: in) {
    while (i < sz(out) && out[i].gas <= gas) {
      Info X = out[i];
      if (X.len > P.len) {
        if (X.r == P.r) P = X;
        else Q = P, P = X;
      } else if (X.len > Q.len) {
        if (X.r != P.r) Q = X;
      }
      i++;
    }

    ans = max(ans, len + (r != P.r ? P.len : Q.len));
  }

  // solve subtrees
  for (auto [v, w]: adj[c]) {
    if (!vst[v]) solve(v);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int u=1; u<=N; u++) cin >> g[u];
  for (int i=0; i<N-1; i++) {
    lld u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  solve(1);

  cout << ans + 1 << endl;

  ////////////////////////////////
  return 0;
}
