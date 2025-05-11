#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
int N, M, vst[MN];
vector<int> adj[MN];

void bfs(int s) {
  queue<int> Q;
  Q.push(s);
  vst[s] = 1;

  while (!Q.empty()) {
    int u = Q.front(); Q.pop();

    for (auto v: adj[u]) {
      if (vst[v]) continue;
      vst[v] = 1;
      Q.push(v);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int cnt = 0;
  for (int u=1; u<=N; u++) {
    if (vst[u]) continue;
    bfs(u);
    cnt++;
  }

  cout << cnt << endl;

  ////////////////////////////////
  return 0;
}
