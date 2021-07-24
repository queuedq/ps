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

int add(Line l) { // returns # of removed lines
  int r = 0;
  while (!lines.empty()) {
    l.s = l.inter(lines.back());
    if (lines.back().s < l.s) break;
    removed.push_back(lines.back());
    lines.pop_back();
    r++;
  }
  lines.push_back(l);
  return r;
}

void rollback(int r) {
  lines.pop_back();
  for (int i=0; i<r; i++) {
    lines.push_back(removed.back());
    removed.pop_back();
  }
}

lld get(lld x) {
  if (lines.empty()) return 0;
  auto it = lower_bound(lines.begin(), lines.end(), (Line){0, 0, (double)x}) - 1;
  return it->a * x + it->b;
}

void dfs(int u, int p, lld d) {
  D[u] = S[u] + V[u] * d + get(V[u]);
  int r = add({-d, D[u]});

  for (auto [v, w]: adj[u]) {
    if (v == p) continue;
    dfs(v, u, d+w);
  }

  rollback(r);
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

  dfs(1, 0, 0);
  
  for (int i=2; i<=N; i++) cout << D[i] << " ";

  ////////////////////////////////
  return 0;
}
