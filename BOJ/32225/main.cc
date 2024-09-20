#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
const lld INF = 1e18;
lld N, M, C[MN];
vector<int> adj[MN];

struct Timeline {
  deque<lld> dq;
  lld zero = 0, len = 0;

  lld get(int i) { return i < sz(dq) ? dq[i] - zero : INF; }

  void merge(Timeline &T) { // merge children timeline
    vector<lld> tmp;
    while (min(get(0), T.get(0)) <= T.len) {
      if (get(0) < T.get(0)) tmp.push_back(get(0)), dq.pop_front();
      else tmp.push_back(T.get(0)), T.dq.pop_front();
    }

    zero -= T.len, len += T.len;
    while (!tmp.empty()) {
      dq.push_front(zero + tmp.back() * 2);
      tmp.pop_back();
    }
  }

  void insert(lld dt) { // insert current water tank
    dq.push_back(zero + len + dt);
    len += dt;
  }

  int filled(lld t) { // count filled water tanks before t
    return upper_bound(all(dq), zero + t) - dq.begin();
  }
};

Timeline T[MN];
int ans;

void dfs(int u) {
  for (auto v: adj[u]) dfs(v);

  if (sz(adj[u]) == 2) { // handle water overflow from child
    int a = adj[u][0], b = adj[u][1];
    if (T[a].len < M) ans = max(ans, sz(T[a].dq) + T[b].filled(M - T[a].len));
    if (T[b].len < M) ans = max(ans, sz(T[b].dq) + T[a].filled(M - T[b].len));
  }

  for (auto v: adj[u]) { // merge
    if (T[u].len < T[v].len) swap(T[u], T[v]);
    T[u].merge(T[v]);
  }
  T[u].insert(C[u]);

  ans = max(ans, T[u].filled(M));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int u=1; u<=N; u++) cin >> C[u];
  for (int u=2; u<=N; u++) {
    int p; cin >> p;
    adj[p].push_back(u);
  }

  dfs(1);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
