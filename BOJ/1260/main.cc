#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
int N, M, V;
vector<int> adj[MAXN];
bool vst1[MAXN], vst2[MAXN];

void dfs(int u) {
  if (vst1[u]) return;
  vst1[u] = true;
  cout << u << " ";

  for (auto v: adj[u]) dfs(v);
}

void bfs(int u) {
  queue<int> q;
  q.push(u);
  vst2[u] = true;

  while (!q.empty()) {
    int u = q.front(); q.pop();
    cout << u << " ";

    for (auto v: adj[u]) {
      if (vst2[v]) continue;
      q.push(v);
      vst2[v] = true;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> V;
  for (int i=0; i<M; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i=1; i<=N; i++) {
    sort(adj[i].begin(), adj[i].end());
  }

  dfs(V);
  cout << endl;
  bfs(V);
  cout << endl;

  ////////////////////////////////
  return 0;
}
