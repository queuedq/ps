#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, Q;
int colors[MN]; // rect i's colors
u64 escape[1<<6]; // for each bit (=mask of colors to use), can we escape the rect?

// tree structure of rects
int par[MN];
vector<int> adj[MN];
vector<int> qry_rect[MN]; // enclosing rect of query points

////////////////////////////////
// LCA
struct Info { int p; u64 m; };

int in[MN], out[MN], now;
Info spa[MN][20];

void dfs(int u) {
  in[u] = now++;;
  spa[u][0] = {par[u], escape[colors[u]]};
  for (auto v: adj[u]) dfs(v);
  out[u] = now++;
}

bool is_anc(int u, int v) { return in[u] <= in[v] && out[v] <= out[u]; } // u is anc of v

Info lca(int u, int v) { // make u anc of v
  u64 mask = 0xFFFF'FFFF'FFFF'FFFFULL;
  if (is_anc(u, v)) return {u, mask};

  for (int k=19; k>=0; k--) {
    auto [p, m] = spa[u][k];
    if (!is_anc(p, v)) u = p, mask &= m;
  }
  auto [p, m] = spa[u][0];
  u = p, mask &= m;

  return {u, mask};
}

////////////////////////////////

struct Event {
  // t = 1: Rect left / 2: Rect right / 3: Query point
  int t, i;
  int x, y1, y2;
  bool operator<(const Event &E) const { return x < E.x; }
};
vector<Event> E;

struct Endpoint {
  // t = 1: Lower end / 2: Upper end
  int t, i, y;
  bool operator<(const Endpoint &E) const { return y < E.y; }
};
set<Endpoint> S;

int find_enclosing_rect(int y) {
  auto it = S.lower_bound({0, 0, y});
  if (it == S.end()) return 0; // whole plane
  if (it->t == 2) return it->i;
  return par[it->i];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  // calculate escapable masks
  for (int c=0; c<1<<6; c++) // rect colors
    for (int m=0; m<1<<6; m++) // selected colors
      if (m & c) escape[c] |= 1ULL<<m;

  // collect events
  cin >> N;
  for (int i=1; i<=N; i++) {
    int x1, y1, x2, y2, c1, c2, c3, c4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> c1 >> c2 >> c3 >> c4; c1--, c2--, c3--, c4--;
    int c = (1<<c1) | (1<<c2) | (1<<c3) | (1<<c4);
    E.push_back({1, i, x1, y1, y2});
    E.push_back({2, i, x2, y1, y2});
    colors[i] = c;
  }

  cin >> Q;
  for (int i=1; i<=Q; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    E.push_back({3, i, x1, y1, 0});
    E.push_back({3, i, x2, y2, 0});
  }

  sort(all(E));

  // sweeping
  for (auto [t, i, x, y1, y2]: E) {
    if (t == 1) {
      par[i] = find_enclosing_rect(y1);
      adj[par[i]].push_back(i);
      S.insert({1, i, y1});
      S.insert({2, i, y2});
    } else if (t == 2) {
      S.erase({1, i, y1});
      S.erase({2, i, y2});
    } else {
      int r = find_enclosing_rect(y1);
      qry_rect[i].push_back(r);
    }
  }

  // prepare LCA
  dfs(0);

  for (int k=1; k<20; k++) {
    for (int i=1; i<=N; i++) {
      auto [p, m1] = spa[i][k-1];
      auto [pp, m2] = spa[p][k-1];
      spa[i][k] = {pp, m1 & m2};
    }
  }

  // LCA
  for (int i=1; i<=Q; i++) {
    int u = qry_rect[i][0];
    int v = qry_rect[i][1];

    auto [x, m1] = lca(u, v);
    auto [_, m2] = lca(v, u);
    u64 mask = m1 & m2;

    int ans = 6;
    for (int m=0; m<1<<6; m++) {
      if (mask>>m & 1) ans = min(ans, __builtin_popcount(m));
    }
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
