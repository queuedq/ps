#include <bits/stdc++.h>
// #define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 255;
int N, deg[MN];
set<pii> adj[MN];

struct Triangle {
  int a, b, c;

  Triangle(vector<int> v) { sort(all(v)); a = v[0], b = v[1], c = v[2]; }
  bool operator<(const Triangle &T) const { return make_tuple(a, b, c) < make_tuple(T.a, T.b, T.c); } 
};

enum SpecialNodes {
  CLOSED = 0, // another end is closed
  MIDDLE = -1, // middle of path
};

struct Connection { // connection state of open nodes via paths
  map<int, int> con; // adjacenct node + CLOSED + MIDDLE
  map<int, int> group; // group number + MIDDLE
  int comps = 0; // already complete paths

  void print() {
    cout << "Connection: con = { ";
    for (auto &[u, v]: con) cout << u << "->" << v << " ";
    cout << "}, group = { ";
    for (auto &[u, g]: group) cout << u << "[" << g << "] ";
    cout << "}" << endl;
  }
};

Connection merge(const vector<Connection> &connections, bool &ok) {
  if (!ok) return {};
  auto NO = [&]() -> Connection { ok = 0; return {}; };

  Connection R; // result
  map<int, vector<int>> adj; // collect all edges
  for (auto &C: connections) {
    R.comps += C.comps;
    for (auto &[u, v]: C.con) adj[u].push_back(v);
  }

  // simple check for graph validity + make it a simple graph
  for (auto &[u, edges]: adj) {
    if (edges.size() > 2) return NO(); // not a path
    if (edges.size() <= 1) continue;

    // deg(u) = 2 case
    int v = edges[0], w = edges[1];
    if (v == MIDDLE || w == MIDDLE) return NO(); // crossing paths
    if (v == CLOSED && w == CLOSED) { edges = {MIDDLE}; R.comps++; continue; } // complete path formed
    if (v == w) return NO(); // loop
    // now v, w are distinct
  }

  // graph traversal to find loops or complete paths + get connection info
  auto find_end = [&](int u, int v) -> int {
    int prv = u;
    while (v != u && v != CLOSED && adj[v].size() == 2) {
      R.con[v] = R.group[v] = MIDDLE; // mark middle of path
      int nxt = (prv != adj[v][0]) ? adj[v][0] : adj[v][1];
      prv = v, v = nxt;
    }
    return v;
  };

  int gcnt = 0;
  for (auto &[u, edges]: adj) {
    if (R.group.count(u)) continue;

    if (edges.size() == 1) {
      if (edges[0] == MIDDLE) { R.con[u] = R.group[u] = MIDDLE; continue; }
      int v = find_end(u, edges[0]);
      if (v == u) return NO(); // loop

      // found u - v path
      gcnt++;
      R.con[u] = v, R.group[u] = gcnt;
      if (v != CLOSED) R.con[v] = u, R.group[v] = gcnt;

    } else {
      assert(edges.size() == 2);
      int v = find_end(u, edges[0]), w = find_end(u, edges[1]);
      if (v == u) return NO(); // loop

      // found v - w path
      R.con[u] = R.group[u] = MIDDLE; // mark middle of path
      if (v == CLOSED && w == CLOSED) { R.comps++; continue; } // complete path formed
      gcnt++;
      if (v != CLOSED) R.con[v] = w, R.group[v] = gcnt;
      if (w != CLOSED) R.con[w] = v, R.group[w] = gcnt;
    }
  }

  // check complete path validity
  if (R.comps >= 2) return NO();
  if (R.comps == 1) {
    for (auto &[u, g]: R.group) {
      if (g != MIDDLE) return NO();
    }
  }

  return R;
}

map<Triangle, int> D;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<3*(N-2); i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].insert({v, w});
    adj[v].insert({u, w});
    deg[u]++, deg[v]++;
  }

  queue<int> Q;
  for (int u=1; u<=N; u++) {
    if (deg[u] == 3) Q.push(u);
  }

  while (!Q.empty()) {
    int u = Q.front(); Q.pop();
    vector<int> vs;
    for (auto [v, w]: adj[u]) vs.push_back(v);
    Triangle T(vs);
    Triangle A({u, T.b, T.c});
    Triangle B({u, T.c, T.a});
    Triangle C({u, T.a, T.b});

    
  }

  ////////////////////////////////
  return 0;
}
