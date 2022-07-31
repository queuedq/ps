#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

const double PI = acos(-1);

struct Point {
  lld x, y;
  Point(): x(0), y(0) {}
  Point(lld x, lld y): x(x), y(y) {}

  bool operator ==(Point a) const { return x == a.x && y == a.y; }
  bool operator !=(Point a) const { return !(*this == a); }
  bool operator <(Point a) const { return pair(x, y) < pair(a.x, a.y); }
  Point operator +(Point a) const { return {x+a.x, y+a.y}; }
  Point operator -(Point a) const { return {x-a.x, y-a.y}; }
  Point operator *(lld c) const { return {x*c, y*c}; }
  Point operator /(lld c) const { return {x/c, y/c}; }
  lld operator *(Point a) const { return x*a.x + y*a.y; }
};

// print
ostream& operator <<(ostream& os, Point a) { return os << "(" << a.x << ", " << a.y << ")"; }

// cross product stuffs
lld cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }
lld ccw(Point a, Point b, Point c) { return cross(b-a, c-a); }

// length and angle
double length(Point a) { return sqrt(a*a); }
lld dist2(Point a, Point b) { return (b-a)*(b-a); }
double dist(Point a, Point b) { return sqrt((b-a)*(b-a)); }
double angle(Point a, Point b) { return atan2(cross(a, b), a * b); }

////////////////////////////////////////////////////////////////
const int _V = 50010, _E = _V*3-6, _F = _V*2-4;
const lld INF = 2e9;
int N, M, F, vst[_E*2];
Point P[_V];

struct Edge {
  lld u, v, w, i, nxt, face;
  Point vector() { return P[v] - P[u]; }
  double angle() { return ::angle({1, 0}, vector()); }
};
vector<Edge> edge;
vector<int> G[_V], H[_F]; // incident edges / G: original, H: dual
vector<pll> G_adj[_V], H_adj[_F];

int twin(int i) { return i<M ? i+M : i-M; }

lld sp1() {
  lld st = 1, ed = N-4;
  vector<lld> dst(N+1, INF);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  dst[st] = 0;
  pq.push({0, st});
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d > dst[u]) continue;
    if (u == ed) break;
    for (auto [v, w]: G_adj[u]) {
      if (d+w < dst[v]) dst[v] = d+w, pq.push({d+w, v});
    }
  }
  return dst[ed];
}

lld sp2() {
  lld st = edge[M-5].face, ed = edge[M-2].face;
  vector<lld> dst(F*2, INF);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  dst[st] = 0;
  pq.push({0, st});
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d > dst[u]) continue;
    if (u == ed+F) break;
    for (auto [v, w]: H_adj[u%F]) {
      if (u < F) {
        if (d+w < dst[v]) dst[v] = d+w, pq.push({d+w, v});
        if (d < dst[v+F]) dst[v+F] = d, pq.push({d, v+F});
      } else {
        if (d+w < dst[v+F]) dst[v+F] = d+w, pq.push({d+w, v+F});
      }
    }
  }
  return dst[ed+F];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int u=1; u<=N; u++) cin >> P[u].x >> P[u].y;
  N += 4;
  P[N-3] = {P[1].x, 0}, P[N-2] = {P[N-4].x, 0};
  P[N-1] = {P[N-4].x, INF}, P[N] = {P[1].x, INF};

  cin >> M;
  for (int i=0; i<M; i++) {
    int u, v, w; cin >> u >> v >> w;
    edge.push_back({u, v, w, i});
  }
  M += 6; // separate bottom and top area
  edge.push_back({1, N-3, INF, M-6});
  edge.push_back({N-3, N-2, INF, M-5});
  edge.push_back({N-2, N-4, INF, M-4});
  edge.push_back({N-4, N-1, INF, M-3});
  edge.push_back({N-1, N, INF, M-2});
  edge.push_back({N, 1, INF, M-1});

  for (int i=0; i<M; i++) {
    auto [u, v, w, j, nxt, face] = edge[i];
    edge.push_back({v, u, w, i+M});
    G[u].push_back(i);
    G[v].push_back(i+M);
    G_adj[u].push_back({v, w});
    G_adj[v].push_back({u, w});
  }

  // build connected edge list
  for (int u=1; u<=N; u++) {
    auto cmp = [=](int i, int j) { return edge[i].angle() < edge[j].angle(); };
    sort(all(G[u]), cmp);

    for (int i=0; i<sz(G[u]); i++) {
      int e = G[u][i], pe = twin(G[u][(i+1)%sz(G[u])]);
      edge[pe].nxt = e;
    }
  }

  // build dual graph
  for (int i=0; i<M*2; i++) {
    if (vst[i]) continue;
    int j = i;
    do {
      vst[j] = 1;
      edge[j].face = F;
      H[F].push_back(j);
      j = edge[j].nxt;
    } while (j != i);
    F++;
  }

  for (int i=0; i<M; i++) {
    int fl = edge[i].face, fr = edge[i+M].face;
    H_adj[fl].push_back({fr, edge[i].w});
    H_adj[fr].push_back({fl, edge[i].w});
  }

  // Dijkstra
  lld tot = 0;
  for (int i=0; i<M-6; i++) tot += edge[i].w;

  cout << sp1() << endl;
  cout << tot - sp2() << endl;

  ////////////////////////////////
  return 0;
}
