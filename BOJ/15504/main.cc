#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 305;
const lld INF = 1e18;

struct Person {
  int a, h, l;
  bool operator<(const Person &rhs) const { return a < rhs.a; }
};
int N;
Person P[MN];

// flow graph
struct Edge { int v, i, rev, cap, w; };
vector<Edge> G[MN*2];
lld dst[MN*2];
pii prv[MN*2];
int M, S, T;

void add_edge(int u, int v, int cap, int w) {
  int i = sz(G[u]), rev = sz(G[v]);
  G[u].push_back({v, i, rev, cap, w});
  G[v].push_back({u, rev, i, 0, -w});
}

void spfa(int s) {
  queue<int> Q;
  vector<int> inq(M+1);
  fill(dst, dst+M+1, INF);
  dst[s] = 0;
  prv[s] = {-1, -1};

  Q.push(s); inq[s] = 1;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop(), inq[u] = 0;

    for (auto &[v, i, rev, cap, w]: G[u]) {
      if (!cap || dst[v] <= dst[u] + w) continue;
      dst[v] = dst[u] + w;
      prv[v] = {u, i};
      if (!inq[v]) Q.push(v), inq[v] = 1;
    }
  }
}

pll flow(int s, int t) { // (flow, cost)
  spfa(s);
  if (dst[t] == INF) return {0, 0};

  lld f = INF, v = t;
  while (v != s) {
    auto [u, i] = prv[v];
    f = min(f, (lld)G[u][i].cap);
    v = u;
  }
  
  v = t;
  while (v != s) {
    auto [u, i] = prv[v];
    G[u][i].cap -= f;
    G[v][G[u][i].rev].cap += f;
    v = u;
  }

  return {f, f*dst[t]};
}

lld mcmf(int s, int t) {
  lld cost = 0;
  while (1) {
    auto [f, c] = flow(s, t);
    if (f == 0) break;
    cost += c;
  }
  return cost;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> P[i].a;
  for (int i=1; i<=N; i++) cin >> P[i].h;
  for (int i=1; i<=N; i++) cin >> P[i].l;
  sort(P+1, P+N+1);

  // build graph
  M = N*2+2, S = M-1, T = M;
  for (int u=1; u<=N-1; u++) {
    for (int v=u+1; v<=N; v++) {
      add_edge(u, N+v, 1, -(P[u].a ^ P[v].a) + P[u].h + P[v].h);
    }
  }
  for (int u=1; u<=N-1; u++) add_edge(S, u, 1, 0);
  for (int u=1; u<=N; u++) {
    int cap = P[u].l - (u != N);
    add_edge(N+u, T, cap, 0);
  }

  // solve
  cout << -mcmf(S, T) << endl;

  ////////////////////////////////
  return 0;
}
