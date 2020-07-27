#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 2e5+5;
int N, M, cnt[MAXN], ans[MAXN];
bool vst[MAXN];
vector<int> adj[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int u=1; u<=N; u++) {
    while (true) {
      int v; cin >> v;
      if (v == 0) break;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }

  for (int u=1; u<=N; u++) {
    cnt[u] = (adj[u].size()+1) / 2;
    ans[u] = -1;
  }

  cin >> M;

  queue<pii> q;
  for (int i=0; i<M; i++) {
    int u; cin >> u;
    q.push({0, u});
    vst[u] = true;
  }

  while (!q.empty()) {
    auto [m, u] = q.front(); q.pop();
    ans[u] = m;

    for (auto v: adj[u]) {
      if (vst[v]) continue;
      cnt[v]--;
      if (cnt[v] == 0) {
        q.push({m+1, v});
        vst[v] = true;
      }
    }
  }

  for (int u=1; u<=N; u++) cout << ans[u] << " ";
  cout << endl;

  ////////////////////////////////
  return 0;
}
