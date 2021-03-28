#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1505;
const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};

int N, M, Q, ax, ay, bx, by;
bool maze[MAXN][MAXN];
vector<int> adj[MAXN*MAXN];

int toInt(int i, int j) { return (i-1)*M + j-1; }
pii toPos(int h) { return {h/M+1, h%M+1}; }

int id, cid, dfn[MAXN*MAXN], low[MAXN*MAXN];
bool bcc_vst[MAXN*MAXN];
vector<int> bcc[MAXN*MAXN];

void dfs(int u, int p) {
  dfn[u] = low[u] = ++id;
  for (auto v: adj[u]) {
    if (v == p) continue;
    if (dfn[v]) {
      low[u] = min(low[u], dfn[v]);
      continue;
    }
    dfs(v, u);
    low[u] = min(low[u], low[v]);
  }
}

void color(int u, int c) {
  bcc_vst[u] = true;
  if (c > 0) bcc[u].push_back(c);
  for (auto v: adj[u]) {
    if (bcc_vst[v]) continue;
    if (low[v] >= dfn[u]){
      bcc[u].push_back(++cid);
      color(v, cid);
    } else {
      color(v, c);
    }
  }
}


struct Pos { int x, y, d; };
bool maze_vst[MAXN][MAXN], pos_vst[MAXN][MAXN][4];
vector<Pos> init_pos;

void fill(int x, int y) {
  if (maze_vst[x][y]) return;
  maze_vst[x][y] = true;

  for (int d=0; d<4; d++) {
    if (pii(x+dx[d], y+dy[d]) == pii(bx, by)) {
      init_pos.push_back({bx, by, d});
    }
    if (maze[x+dx[d]][y+dy[d]]) {
      fill(x+dx[d], y+dy[d]);
    }
  }
}

void dfs2(Pos p) {
  if (pos_vst[p.x][p.y][p.d]) return;
  pos_vst[p.x][p.y][p.d] = true;

  for (int d=0; d<4; d++) {
    if (d == p.d && maze[p.x+dx[d]][p.y+dy[d]]) {
      dfs2({p.x+dx[d], p.y+dy[d], p.d});
      continue;
    }

    int x1 = p.x-dx[p.d], y1 = p.y-dy[p.d];
    int x2 = p.x-dx[d], y2 = p.y-dy[d];
    if (!maze[x2][y2]) continue;

    bool same_bcc = false;
    for (auto c1: bcc[toInt(x1, y1)]) {
      for (auto c2: bcc[toInt(x2, y2)]) {
        if (c1 == c2) same_bcc = true;
      }
    }

    if (same_bcc) dfs2({p.x, p.y, d});
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  // Input
  cin >> N >> M >> Q;
  for (int i=1; i<=N; i++) {
    string s; cin >> s;
    for (int j=1; j<=M; j++) {
      if (s[j-1] != '#') maze[i][j] = true;
      if (s[j-1] == 'A') { ax = i; ay = j; }
      if (s[j-1] == 'B') { bx = i, by = j; }
    }
  }

  // Construct maze graph
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) {
      if (!maze[i][j]) continue;

      for (int d=0; d<4; d++) {
        if (maze[i+dx[d]][j+dy[d]]) {
          adj[toInt(i, j)].push_back(toInt(i+dx[d], j+dy[d]));
        }
      }
    }
  }

  // Find BCC
  dfs(toInt(bx, by), -1);
  color(toInt(bx, by), 0);

  // Find reachable positions
  maze[bx][by] = false;
  fill(ax, ay);
  maze[bx][by] = true;

  for (auto p: init_pos) dfs2(p);

  // Query
  for (int q=0; q<Q; q++) {
    int x, y; cin >> x >> y;
    bool ok = false;
    if (x == bx && y == by) ok = true;
    for (int d=0; d<4; d++) {
      if (pos_vst[x][y][d]) ok = true;
    }
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  // DEBUG

  // for (int i=1; i<=N; i++) {
  //   for (int j=1; j<=M; j++) {
  //     cout << i << "," << j << ": ";
  //     // cout << dfn[toInt(i, j)] << " ";
  //     for (auto c: bcc[toInt(i, j)]) {
  //       cout << c << " ";
  //     }
  //     cout << "/ ";
  //   }
  //   cout << endl;
  // }

  // for (auto p: init_pos) cout << p.x << " " << p.y << " " << p.d << endl;

  // for (int i=1; i<=N; i++) {
  //   for (int j=1; j<=M; j++) {
  //     for (int d=0; d<4; d++) {
  //       cout << pos_vst[i][j][d];
  //     }
  //     cout << " ";
  //   }
  //   cout << endl;
  // }

  ////////////////////////////////
  return 0;
}
