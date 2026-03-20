#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2020;
int N, M, dsu[MN];
vector<int> S[MN];

void reset_dsu() {
  for (int u=1; u<=N; u++) dsu[u] = u, S[u].clear();
}

int find(int x) {
  if (x == dsu[x]) return x;
  return dsu[x] = find(dsu[x]);
}

////////////////////////////////

struct Constraint { int a, b, c, d; };
Constraint C[MN];

int last;
set<int> children[MN*2];
int par[MN*2];

bool solve(int root) {
  auto &G = children[root];

  // collect constraints
  deque<pii> Q; // merge a-b (or a-b-c-d when c-d happens)
  vector<vector<pii>> evt(N+1); // detect c-d merge event
  for (int i=1; i<=M; i++) {
    auto [a, b, c, d] = C[i];
    if (G.count(c) && G.count(d)) {
      Q.push_back({a, b});
      evt[c].push_back({i, d});
      evt[d].push_back({i, c});
    }
  }

  // merge
  reset_dsu();
  for (auto u: G) S[u].push_back(u);

  while (!Q.empty()) {
    auto [a, b] = Q.front(); Q.pop_front();
    a = find(a), b = find(b);
    if (a == b) continue;
    if (sz(S[a]) < sz(S[b])) swap(a, b);

    for (auto u: S[b]) {
      for (auto [i, v]: evt[u]) {
        if (find(v) == a) { // c-d detected -> merge a-b-c-d
          Q.push_back({C[i].c, C[i].a});
          Q.push_back({C[i].c, C[i].b});
        }
      }
    }

    dsu[b] = a;
    for (auto u: S[b]) S[a].push_back(u);
    S[b].clear();
  }

  // add children
  for (int u=1; u<=N; u++) {
    if (S[u].empty()) continue;
    if (S[u].size() == G.size()) return 0; // only one group -> impossible

    if (S[u].size() == 1) { par[u] = root; continue; }
    par[++last] = root;
    for (auto v: S[u]) children[last].insert(v);
  }

  return 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=M; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    C[i] = {a, b, c, d};
  }

  last = N+1;
  for (int u=1; u<=N; u++) children[last].insert(u);

  // solve
  bool ok = 1;
  for (int r=N+1; ok && r<=last; r++) ok &= solve(r);

  // print
  if (!ok) { cout << -1 << endl; return 0; }
  
  cout << last << endl;
  for (int u=1; u<=last; u++) cout << par[u] << " ";

  ////////////////////////////////
  return 0;
}
