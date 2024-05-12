#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;
const int MN = 505;
lld N, M, K, A[MN], vst[MN], t[MN], c[MN];

struct Edge {
  lld u, v, w;
  bool operator<(const Edge &rhs) const { return w < rhs.w; }
};
vector<Edge> E;
int G[MN];

int simulate(int u, lld bound, int vn) {
  vst[u] = vn;

  // find loop
  lld len = 0, sum = 0;
  while (t[u] < K && (bound == -1 || c[u] < bound)) {
    int v = G[u];
    if (vst[v] == vn) { // found
      len = t[u] - t[v] + 1;
      sum = c[u] - c[v] + A[v];
      if (bound == -1) sum = (sum % MOD + MOD) % MOD;
      break;
    }

    vst[v] = vn;
    t[v] = t[u] + 1;
    c[v] = c[u] + A[v];
    if (bound == -1) c[v] %= MOD;
    u = v;
  }
  if (len == 0) return u;

  // skip loops
  lld s = (K - t[u]) / len;
  if (bound != -1 && sum > 0) s = min(s, (bound - c[u]) / sum);
  t[u] += s * len;
  if (bound != -1) c[u] += s * sum;
  else c[u] = (c[u] + (s % MOD) * sum) % MOD;

  // remaining
  while (t[u] < K && (bound == -1 || c[u] < bound)) {
    int v = G[u];
    t[v] = t[u] + 1;
    c[v] = c[u] + A[v];
    if (bound == -1) c[v] %= MOD;
    u = v;
  }

  return u;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int u=1; u<=N; u++) cin >> A[u];
  for (int i=0; i<M; i++) {
    lld u, v, w; cin >> u >> v >> w;
    E.push_back({u, v, w});
  }
  sort(all(E));

  // init
  for (int u=1; u<=N; u++) G[u] = u;

  // solve
  int u = 1;
  for (int i=0; i<M && K>0; i++) {
    u = simulate(u, E[i].w, i+1);
    G[E[i].u] = E[i].v;
  }
  u = simulate(u, -1, M+1);

  cout << u << " " << (c[u] % MOD) << endl;

  ////////////////////////////////
  return 0;
}
