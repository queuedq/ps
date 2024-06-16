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
int N, M, idx[MN], ord[MN], k;
vector<int> adj[MN], rev[MN];
int E[MN];

void dfs(int u) {
  if (idx[u]) return;
  idx[u] = -1;
  for (auto v: adj[u]) dfs(v);
  ord[k] = u;
  idx[u] = k--;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    rev[v].push_back(u);
  }

  k = N;
  for (int u=1; u<=N; u++) dfs(u);

  for (int u=1; u<=N; u++) {
    int l = 0, r = N+1;
    for (auto v: adj[u]) r = min(r, idx[v]);
    for (auto v: rev[u]) l = max(l, idx[v]);
    E[l+1]++; E[u]--;
    E[u+1]++; E[r]--;
  }

  vector<int> ans;
  int cnt = 0;
  for (int i=1; i<=N; i++) {
    cnt += E[i];
    if (cnt == 0) ans.push_back(ord[i]);
  }

  sort(all(ans));
  cout << sz(ans) << endl;
  for (auto x: ans) cout << x << ' ';
  cout << endl;

  ////////////////////////////////
  return 0;
}
