#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 10101;

struct Point {
  int x, y, u;
  bool operator<(Point P) const { return pii(x, y) < pii(P.x, P.y); }
};

int N, M, color[MN], d[MN][5], vst[MN], vn, linked;
Point P[MN];
vector<int> adj[MN];

int find_color(int u) {
  int used[5] = {};
  for (auto v: adj[u]) used[color[v]] = 1;
  for (int c=1; c<=4; c++)
    if (!used[c]) return c;
  return 0;
}

void dfs(int u, int r, int ca, int cb) {
  if (vst[u] == vn) return;
  vst[u] = vn;

  for (auto v: adj[u]) {
    int c = color[v];
    if (v == r) linked = 1;
    else if (c == ca || c == cb) dfs(v, r, ca, cb);

    if (linked) return;
  }
}

void flip(int u, int ca, int cb) {
  if (vst[u] == vn) return;
  vst[u] = vn;
  color[u] = ca + cb - color[u];

  for (auto v: adj[u]) {
    int c = color[v];
    if (c == ca || c == cb) flip(v, ca, cb);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) {
    int x, y; cin >> x >> y;
    P[i] = {x, y, i};
  }
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);

    for (int _: {0, 1}) {
      int dx = P[v].x - P[u].x, dy = P[v].y - P[u].y;
      if (dx == 0 && dy < 0) d[u][1] = v;
      if (dx < 0 && dy < 0) d[u][2] = v;
      if (dx < 0 && dy == 0) d[u][3] = v;
      if (dx < 0 && dy > 0) d[u][4] = v;
      swap(u, v);
    }
  }

  sort(P+1, P+N+1);
  for (int i=1; i<=N; i++) {
    auto [x, y, u] = P[i];
    int c = find_color(u);
    if (c) { color[u] = c; continue; } 

    // adj to 4 colors: kempe chain
    vn++, linked = 0;
    int v1 = d[u][1], v2 = d[u][2], v3 = d[u][3], v4 = d[u][4];
    dfs(v1, v3, color[v1], color[v3]);
    
    vn++;
    if (!linked) flip(v1, color[v1], color[v3]);
    else flip(v2, color[v2], color[v4]);

    // color
    color[u] = find_color(u);
  }

  for (int u=1; u<=N; u++) cout << color[u] << endl;

  ////////////////////////////////
  return 0;
}
