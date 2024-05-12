#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
// max flow
const int INF = 1e9;
const int MV = 2020; // two towers per row/col, 9 lasers per tower -> 50*2*2*9 ~= 2000
int V = 2, S = 0, T = 1; // 0, 1 reserved for S, T
int cap[MV][MV], par[MV];
vector<int> G[MV];

void add_edge(int u, int v, int w) {
  // cout << u << " -> " << v << ": " << w << endl;
  G[u].push_back(v);
  G[v].push_back(u);
  cap[u][v] = w;
}

int flow() {
  fill(par, par+V, -2);
  deque<pii> Q = {{S, INF}};
  par[S] = -1;

  while (!Q.empty()) {
    auto [u, f] = Q.front(); Q.pop_front();
    for (auto v: G[u]) {
      if (cap[u][v] == 0 || par[v] != -2) continue;
      par[v] = u;
      if (v == T) return min(f, cap[u][v]);
      Q.push_back({v, min(f, cap[u][v])});
    }
  }
  return 0;
}

int max_flow() {
  int sum = 0, f = 0;
  while ((f = flow())) {
    for (int u=T; u!=S; u=par[u]) {
      cap[par[u]][u] -= f;
      cap[u][par[u]] += f;
    }
    sum += f;
  }
  return sum;
}

////////////////////////////////////////////////////////////////
const int MN = 55;
int N, M, hor[MN][MN], tot;
char A[MN][MN];

int num(char c) { if ('1' <= c && c <= '9') return c - '0'; else return 0; }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int r=0; r<N; r++) for (int c=0; c<M; c++) cin >> A[r][c];

  // horizontal
  // >
  for (int r=0; r<N; r++) {
    vector<int> xs; int last = 10;
    for (int c=0; c<M; c++) if (A[r][c] != '.') {
      if (A[r][c] == '>') last = 0, xs.push_back(c);
      else if (num(A[r][c]) > last) last = num(A[r][c]), xs.push_back(c);
    }
    if (sz(xs) <= 1) continue;

    // make graph
    int mx = num(A[r][xs.back()]); tot += mx;
    for (int i=1, u=S, v; i<sz(xs); i++, u=v) {
      add_edge(u, v=V++, mx - num(A[r][xs[i-1]]));
      for (int c=xs[i]; c>xs[i-1]; c--) hor[r][c] = v;
    }
  }

  // <
  for (int r=0; r<N; r++) {
    vector<int> xs; int last = 10;
    for (int c=M-1; c>=0; c--) if (A[r][c] != '.') {
      if (A[r][c] == '<') last = 0, xs.push_back(c);
      else if (num(A[r][c]) > last) last = num(A[r][c]), xs.push_back(c);
    }
    if (sz(xs) <= 1) continue;

    // make graph
    int mx = num(A[r][xs.back()]); tot += mx;
    for (int i=1, u=S, v; i<sz(xs); i++, u=v) {
      add_edge(u, v=V++, mx - num(A[r][xs[i-1]]));
      for (int c=xs[i]; c<xs[i-1]; c++) hor[r][c] = v;
    }
  }

  // vertical
  // V
  for (int c=0; c<M; c++) {
    vector<int> xs; int last = 10;
    for (int r=0; r<N; r++) if (A[r][c] != '.') {
      if (A[r][c] == 'V') last = 0, xs.push_back(r);
      else if (num(A[r][c]) > last) last = num(A[r][c]), xs.push_back(r);
    }
    if (sz(xs) <= 1) continue;

    // make graph
    int mx = num(A[xs.back()][c]); tot += mx;
    for (int i=1, u, v=T; i<sz(xs); i++, v=u) {
      add_edge(u=V++, v, mx - num(A[xs[i-1]][c]));
      for (int r=xs[i]; r>xs[i-1]; r--) if (hor[r][c]) add_edge(hor[r][c], u, 9);
    }
  }

  // A
  for (int c=0; c<M; c++) {
    vector<int> xs; int last = 10;
    for (int r=N-1; r>=0; r--) if (A[r][c] != '.') {
      if (A[r][c] == 'A') last = 0, xs.push_back(r);
      else if (num(A[r][c]) > last) last = num(A[r][c]), xs.push_back(r);
    }
    if (sz(xs) <= 1) continue;

    // make graph
    int mx = num(A[xs.back()][c]); tot += mx;
    for (int i=1, u, v=T; i<sz(xs); i++, v=u) {
      add_edge(u=V++, v, mx - num(A[xs[i-1]][c]));
      for (int r=xs[i]; r<xs[i-1]; r++) if (hor[r][c]) add_edge(hor[r][c], u, 9);
    }
  }

  // find min cut
  int f = max_flow();
  cout << tot - f << endl;

  ////////////////////////////////
  return 0;
}
