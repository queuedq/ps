#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
int N, M, L[MN], R[MN], vst[MN], S[MN], E[MN], ans[MN];
vector<int> front[MN], back[MN];

struct Interval {
  int u, s, e;
  bool operator<(const Interval &I) const { return s < I.s; }
};

int NO() { cout << -1 << endl; return 0; }

bool dfs_back(int u) {
  if (vst[u]) return E[u] != 0;
  vst[u] = 1;

  E[u] = R[u];
  for (auto v: back[u]) {
    if (!dfs_back(v)) return 0;
    E[u] = min(E[u], E[v] - 1);
  }
  return E[u] >= 1;
}

bool dfs_front(int u) {
  if (vst[u]) return S[u] != 0;
  vst[u] = 1;

  S[u] = L[u];
  for (auto v: front[u]) {
    if (!dfs_front(v)) return 0;
    S[u] = max(S[u], S[v] + 1);
  }
  return S[u] <= N;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int u=1; u<=N; u++) cin >> L[u] >> R[u];
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    back[u].push_back(v);
    front[v].push_back(u);
  }

  // calc actual possible intervals [S, E]
  fill(vst, vst+N+1, 0);
  for (int u=1; u<=N; u++) {
    if (!dfs_back(u)) return NO();
  }
  fill(vst, vst+N+1, 0);
  for (int u=1; u<=N; u++) {
    if (!dfs_front(u)) return NO();
  }

  vector<Interval> I;
  for (int u=1; u<=N; u++) I.push_back({u, S[u], E[u]});
  sort(all(I));

  // greedy
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  for (int i=1, j=0; i<=N; i++) {
    for (; j < N && I[j].s == i; j++) pq.push({I[j].e, I[j].u});
    if (pq.empty()) return NO();
    auto [e, u] = pq.top(); pq.pop();
    if (e < i) return NO();
    ans[i] = u;
  }

  for (int i=1; i<=N; i++) cout << ans[i] << endl;

  ////////////////////////////////
  return 0;
}
