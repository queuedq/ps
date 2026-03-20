#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3;
const int MN = 55;
const int MV = 10101;
int N, M, K;
char A[MN][MN];
unordered_set<int> removed;

// flow graph
int V, E;
vector<int> adj[MV];
int dir[MV][MV], cap[MV][MV];
int par[MV];

int node(int a, int b, int dir) {
  return (a*M + b) * 4 + dir;
}

void add_edge(int u, int v, bool rev=false) {
  if (rev) swap(u, v);
  if (removed.count(u) || removed.count(v)) return;
  adj[u].push_back(v);
  adj[v].push_back(u);
  dir[u][v] = 1;
  cap[u][v] = 1;
}

int bfs(int s, int t) {
  fill(par, par+V, -1);
  queue<int> Q;
  par[s] = s; Q.push(s);

  while (!Q.empty()) {
    int u = Q.front(); Q.pop();
    for (auto v: adj[u]) {
      if (par[v] != -1 || cap[u][v] == 0) continue;
      par[v] = u; Q.push(v);
      if (v == t) return 1;
    }
  }
  return 0;
}

int max_flow(int s, int t) {
  int f = 0, total = 0;
  while ((f = bfs(s, t))) {
    // send flow
    int u = t;
    while (u != s) {
      int p = par[u];
      cap[p][u]--;
      cap[u][p]++;
      u = p;
    }
    total += f;
  }
  return total;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) cin >> A[i][j];
  }
  for (int i=0; i<K; i++) {
    int d, a, b; cin >> d >> a >> b; a--; b--;
    if (d == 0) removed.insert(node(a, b, DOWN));
    else removed.insert(node(a, b, RIGHT));
  }
  V = N * M * 4 + 2;

  // build graph
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      bool p = (i+j) & 1;
      int u = node(i, j, UP);
      int d = node(i, j, DOWN);
      int l = node(i, j, LEFT);
      int r = node(i, j, RIGHT);

      // connect inside cell
      if (A[i][j] != '/') add_edge(u, r, p), add_edge(d, l, p);
      if (A[i][j] != '\\') add_edge(u, l, p), add_edge(d, r, p);
      // connect between cells
      if (i > 0) add_edge(node(i-1, j, DOWN), u, p);
      if (j > 0) add_edge(l, node(i, j-1, RIGHT), p);
    }
  }

  // connect source and sink
  int S = V-2, T = V-1;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      bool p = (i+j) & 1;
      int u = node(i, j, UP);
      int d = node(i, j, DOWN);
      int l = node(i, j, LEFT);
      int r = node(i, j, RIGHT);

      if (i == 0) !p ? add_edge(S, u) : add_edge(u, T);
      if (i == N-1) !p ? add_edge(S, d) : add_edge(d, T);
      if (j == 0) p ? add_edge(S, l) : add_edge(l, T);
      if (j == M-1) p ? add_edge(S, r) : add_edge(r, T);
    }
  }

  // max flow
  int flow = max_flow(S, T);
  if (flow < N+M) {
    cout << "NO" << endl;
    return 0;
  }

  // construct grid
  cout << "YES" << endl;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      int u = node(i, j, UP);
      int d = node(i, j, DOWN);
      int l = node(i, j, LEFT);
      int r = node(i, j, RIGHT);

      // flow existence
      bool ul = cap[u][l] < dir[u][l] || cap[l][u] < dir[l][u];
      bool ur = cap[u][r] < dir[u][r] || cap[r][u] < dir[r][u];
      bool dl = cap[d][l] < dir[d][l] || cap[l][d] < dir[l][d];
      bool dr = cap[d][r] < dir[d][r] || cap[r][d] < dir[r][d];

      assert(!((ul || dr) && (ur || dl))); // no crossing

      if (A[i][j] != '.') cout << A[i][j];
      else if (ul || dr) cout << '/';
      else if (ur || dl) cout << '\\';
      else cout << '/'; // any
    }
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
