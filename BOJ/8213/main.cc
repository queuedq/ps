#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9;
const int MN = 303030;
// dst: max dist to uncovered dynamite
// F: fire strength that came from subtrees
int N, M, A[MN], dst[MN], F[MN];
vector<int> adj[MN];

void dfs(int u, int p, int r, int &cnt) { // r: radius
  dst[u] = A[u] ? 0 : -INF;
  F[u] = -INF;

  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u, r, cnt);
    dst[u] = max(dst[u], dst[v]+1);
    F[u] = max(F[u], F[v]-1);
  }

  // cover dynamites
  if (dst[u] <= F[u]) dst[u] = -INF;

  // place fire (defer until dst = r or root)
  if (dst[u] == r || (dst[u] >= 0 && p == 0))
    dst[u] = -INF, F[u] = r, cnt++;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int l = -1, r = N;
  while (l+1 < r) {
    int m = (l+r)/2;
    int cnt = 0;
    dfs(1, 0, m, cnt);

    if (cnt <= M) r = m;
    else l = m;
  }

  cout << r << endl;

  ////////////////////////////////
  return 0;
}
