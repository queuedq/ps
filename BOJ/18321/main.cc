#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, M, P[MAXN];
vector<pii> adj[MAXN];

void dfs(int u, int p, int x, int id, vector<int> &conn) {
  if (conn[u] > 0) return;
  conn[u] = id;
  for (auto [v, w]: adj[u]) {
    if (v == p || w < x) continue;
    dfs(v, u, x, id, conn);
  }
}

bool check(int x) {
  vector<int> conn(N+1);

  for (int i=1; i<=N; i++) {
    dfs(i, 0, x, i, conn);
  }

  int ans = true;
  for (int i=1; i<=N; i++) {
    if (conn[i] != conn[P[i]]) { ans = false; break; }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) cin >> P[i];
  for (int i=1; i<=M; i++) {
    int a, b, w; cin >> a >> b >> w;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }

  int l = 0, r = 1e9+5;
  while (l+1 < r) {
    int mid = (l+r) / 2;
    if (check(mid)) l = mid;
    else r = mid;
  }

  cout << (l > 1e9 ? -1 : l) << endl;

  ////////////////////////////////
  return 0;
}
