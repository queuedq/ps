#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;

enum State { LINEAR = 1, CYCLE = 2, DEG_3 = 3, IMPOSSIBLE = 9 };

struct Graph {
  vector<int> adj[MN];

  void make_edge(int u, int v) { adj[u].push_back(v), adj[v].push_back(u); }
  int deg(int u) { return sz(adj[u]); }
};

struct DSU { // linear forest
  int par[MN], e[2][MN]; // e: both ends

  void init(int N) {
    for (int i=0; i<N; i++) par[i] = e[0][i] = e[1][i] = i;
  }
  
  int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
  }

  bool merge(int x, int y) { // return 0 if failed
    int r = find(x), s = find(y);
    if (r == s) return 0; // cycle

    if (x == e[0][r]) swap(e[0][r], e[1][r]);
    if (y == e[0][s]) swap(e[0][s], e[1][s]);
    if (x != e[1][r] || y != e[1][s]) return 0; // deg 3

    par[s] = r;
    e[1][r] = e[0][s];
    return 1;
  }
};

int N, Q;
State state = State::LINEAR;
vector<int> cand;
Graph G;
DSU D[4];
bool good[4];


// utils

int cnt_cyc, cyc[MN];

void mark_cycle(int u) {
  if (cyc[u]) return;
  cyc[u] = 1, cnt_cyc++;
  for (auto v: G.adj[u]) mark_cycle(v);
}

void link_d3(int i, int u, int v) {
  if (u == cand[i] || v == cand[i]) return;
  good[i] &= D[i].merge(u, v);
}

void build_graph(int i) {
  D[i].init(N);
  good[i] = 1;

  for (int u=0; u<N; u++)
    for (auto v: G.adj[u])
      if (u < v) link_d3(i, u, v);
}


// queries

int count() {
  if (state == State::LINEAR) return N;
  if (state == State::CYCLE) return cnt_cyc;
  if (state == State::DEG_3) {
    int cnt = 0;
    for (int i=0; i<4; i++) cnt += good[i];
    return cnt;
  }
  return 0; // IMPOSSIBLE
}

void link(int u, int v) {
  if (state == State::LINEAR || state == State::CYCLE) {
    G.make_edge(u, v);
    bool ok = D[0].merge(u, v);

    // check deg 3
    if (G.deg(u) == 3 || G.deg(v) == 3) {
      state = State::DEG_3;

      // get cand
      if (G.deg(v) == 3) swap(u, v);
      cand.push_back(u);
      for (auto v: G.adj[u]) cand.push_back(v);

      for (int i=0; i<4; i++) build_graph(i);
      return;
    }

    // check cycle
    if (!ok) {
      if (state == State::LINEAR) state = State::CYCLE, mark_cycle(u);
      else state = State::IMPOSSIBLE;
    }

  } else if (state == State::DEG_3) {
    for (int i=0; i<4; i++)
      if (good[i]) link_d3(i, u, v);

  } // IMPOSSIBLE
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> Q;
  D[0].init(N);

  for (int q=1; q<=Q; q++) {
    int a, b = -1; cin >> a;
    if (a != -1) cin >> b;

    if (a == -1) cout << count() << endl;
    else link(a, b);
  }

  ////////////////////////////////
  return 0;
}
