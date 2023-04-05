#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505;
const int MK = 2005;
int N, M, K, vst[MN], ans[MK];
vector<int> adj[MN];

bool dfs(int u, int d) { // u -> d reachable?
  if (u == d) return true;
  vst[u] = true;
  for (auto v: adj[u]) {
    if (vst[v]) continue;
    bool res = dfs(v, d);
    if (res) return true;
  }
  return false;
}

void solve(int test) {
  cin >> N >> M >> K;
  for (int i=1; i<=N; i++) adj[i].clear();
  
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
  }

  for (int i=0; i<K; i++) {
    int u, v; cin >> u >> v;
    fill(vst, vst+N+1, 0);

    if (dfs(v, u)) {
      ans[i] = 1; // can't add u -> v
      // adj[v].push_back(u); // not necessary because v -> u is already reachable
    } else {
      ans[i] = 0;
      adj[u].push_back(v);
    }
  }

  cout << "Case #" << test << endl;
  for (int i=0; i<K; i++) cout << ans[i];
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
