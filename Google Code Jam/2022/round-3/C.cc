#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;
const string chr = "ACDEHIJKMORST";
int N, L[MN], R[MN], deg[MN], vst[MN], C[MN];
vector<int> adj[MN], ord;
char ans[MN];

void reset() {
  ord.clear();
  for (int u=1; u<=N; u++) {
    adj[u].clear();
    deg[u] = vst[u] = C[u] = ans[u-1] = 0;
  }
}

void solve(int test) {
  cin >> N;
  for (int u=1; u<=N; u++) cin >> L[u];
  for (int u=1; u<=N; u++) cin >> R[u];

  vector<pii> edges;
  for (int u=1; u<=N; u++) {
    auto V = {L[u], R[u], L[L[u]], L[R[u]], R[L[u]], R[R[u]]};
    for (auto v: V) {
      if (u == v) {
        cout << "Case #" << test << ": " << "IMPOSSIBLE" << endl;
        return;
      }
      edges.push_back({u, v});
      edges.push_back({v, u});
    }
  }
  sort(all(edges));
  edges.erase(unique(all(edges)), edges.end());

  for (auto [u, v]: edges) {
    adj[u].push_back(v);
    deg[u]++;
  }

  queue<int> Q;
  for (int u=1; u<=N; u++) {
    if (deg[u] <= 12) Q.push(u);
  }

  while (!Q.empty()) {
    int u = Q.front(); Q.pop();
    if (vst[u]) continue;
    vst[u] = 1;
    ord.push_back(u);

    for (auto v: adj[u]) {
      if (vst[v]) continue;
      deg[v]--;
      if (deg[v] <= 12) Q.push(v);
    }
  }

  assert(ord.size() == N);
  reverse(all(ord));

  for (auto u: ord) {
    vector<int> used(14);
    for (auto v: adj[u]) used[C[v]] = 1;
    for (int c=1; c<=13; c++) {
      if (!used[c]) { C[u] = c; break; }
    }
  }

  for (int u=1; u<=N; u++) ans[u-1] = chr[C[u]-1];
  cout << "Case #" << test << ": " << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
    reset();
  }

  ////////////////////////////////
  return 0;
}
