#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 10101;
int N, M, vst[MN];
vector<pii> edge;
vector<int> adj[MN], poly[MN];

void dfs(int u, int a, int b, int &cnt) { // erase nodes a, b
  vst[u] = 1;
  cnt++;
  for (auto v: adj[u]) {
    if (vst[v] || v == a || v == b) continue;
    dfs(v, a, b, cnt);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N+M; i++) {
    int u, v; cin >> u >> v;
    edge.push_back({u, v});
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // check if removing edge separates graph
  for (int i=0; i<N+M; i++) {
    auto [a, b] = edge[i];
    int r = 1, cnt = 0;
    while (r == a || r == b) r++;

    fill(vst, vst+N+1, 0);
    dfs(r, a, b, cnt);
    if (cnt == N-2) {
      poly[a].push_back(b);
      poly[b].push_back(a);
    }
  }

  // reconstruct polygon
  sort(all(poly[1]));

  int u = 1, p = 0;
  do {
    cout << u << ' ';
    int v = poly[u][0];
    if (v == p) v = poly[u][1];
    p = u;
    u = v;
  } while (u != 1);

  ////////////////////////////////
  return 0;
}
