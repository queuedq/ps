#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
lld N, M, par[MN];
struct Edge {
  lld u, v, w;
  bool operator <(const Edge &E) const { return w < E.w; }
};
Edge E[MN];

int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

void merge(int x, int y) {
  par[find(y)] = find(x);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) cin >> E[i].u >> E[i].v >> E[i].w;
  sort(E, E+M);
  reverse(E, E+M);

  lld A = 0;
  for (lld i=N; i>=2; i--) A += (i/2) * (i-i/2);

  lld B = 0;
  iota(par+1, par+N+1, 1);
  for (int i=0; i<M; i++) {
    auto [u, v, w] = E[i];
    if (find(u) == find(v)) continue;
    merge(u, v);
    B += w;
  }

  if (A > B) cout << "win" << endl;
  else if (A == B) cout << "tie" << endl;
  else cout << "lose" << endl;

  ////////////////////////////////
  return 0;
}
