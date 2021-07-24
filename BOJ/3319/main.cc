#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
lld N, S[MN], V[MN], D[MN];
vector<pll> adj[MN];

struct Line {
  lld a, b; double s = 0;
  double inter(Line l) { return (double)(b - l.b) / (l.a - a); }
  bool operator <(const Line &l) const { return s < l.s; }
};
vector<Line> lines, removed;

int add(Line l, int sz) { // returns added index
  int s = 0, e = sz;
  while (s+1 < e) {
    int m = (s+e) / 2;
    l.s = l.inter(lines[m]);
    if (lines[m].s < l.s) s = m;
    else e = m;
  }
  if (e == lines.size()) lines.resize(e+1);
  removed.push_back(lines[e]);
  if (e > 0) l.s = l.inter(lines[e-1]);
  lines[e] = l;
  return e;
}

void rollback(int i) {
  lines[i] = removed.back();
  removed.pop_back();
}

lld get(lld x, int sz) {
  if (sz == 0) return 0;
  auto it = lower_bound(lines.begin(), lines.begin()+sz, (Line){0, 0, (double)x}) - 1;
  return it->a * x + it->b;
}

void dfs(int u, int p, lld d, int sz) {
  D[u] = S[u] + V[u] * d + get(V[u], sz);
  int i = add({-d, D[u]}, sz);

  for (auto [v, w]: adj[u]) {
    if (v == p) continue;
    dfs(v, u, d+w, i+1);
  }

  rollback(i);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    lld u, v, d; cin >> u >> v >> d;
    adj[u].push_back({v, d});
    adj[v].push_back({u, d});
  }
  for (int i=2; i<=N; i++) cin >> S[i] >> V[i];

  dfs(1, 0, 0, 0);
  
  for (int i=2; i<=N; i++) cout << D[i] << " ";

  ////////////////////////////////
  return 0;
}
