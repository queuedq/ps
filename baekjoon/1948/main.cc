#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 10005;
int N, M, start, finish;
vector<pii> adj[MAX_N];
vector<bool> visited[MAX_N];
int D[MAX_N];


void input() {
  cin >> N >> M;
  for (int i=1; i<=M; i++) {
    int a, b, w; cin >> a >> b >> w;
    adj[b].push_back({a, w});
    visited[b].push_back(false);
  }
  cin >> start >> finish;
}

int dfs1(int node) {
  if (D[node]) { return D[node]; }
  if (node == start) { return D[node] = 0; }

  int maxCost = 0;

  for (pii edge: adj[node]) {
    int c, w;
    tie(c, w) = edge;

    int cost = dfs1(c) + w;
    if (cost > maxCost) maxCost = cost;
  }

  return D[node] = maxCost;
}

int dfs2(int node, int cost) {
  int res = 0;

  for (int i=0; i<adj[node].size(); i++) {
    int c, w;
    tie(c, w) = adj[node][i];

    if (visited[node][i]) { continue; }
    if (D[c] + w < cost) { continue; }
    // cout << c << " " << cost << " " << D[c] << " " << w << endl;
    // assert(cost == D[c] + w);

    visited[node][i] = true;
    res += dfs2(c, D[c]) + 1;
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  int cost = dfs1(finish);
  int cnt = dfs2(finish, cost);
  cout << cost << " " << cnt << endl;

  ////////////////////////////////
  return 0;
}
