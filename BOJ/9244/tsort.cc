#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
struct Line {
  lld x, y, z, w, i;

  double f(lld t) const {
    return (t-x) * (w-y) / (double)(z-x) + y;
  }

  bool operator<(const Line &L) const {
    lld t = max(x, L.x);
    return f(t) < L.f(t);
  }
};

const int MN = 1e5+5;
int N, x0;
Line L[MN];
vector<pair<pll, int>> E;
set<Line> S;
vector<int> adj[MN], tsort;
bool vst[MN];

void dfs(int u) {
  if (vst[u]) return;
  vst[u] = true;
  for (int v: adj[u]) dfs(v);
  tsort.push_back(u);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int x, y, z, w; cin >> x >> y >> z >> w;
    if (x > z) { swap(x, z); swap(y, w); }
    L[i] = {x, y, z, w, i};
    E.push_back({{x, 0}, i});
    E.push_back({{z, 1}, i});
  }
  cin >> x0;

  sort(E.begin(), E.end());

  for (auto [e, i]: E) {
    auto [x, type] = e;
    if (type == 0) { // insert
      auto [it, _] = S.insert(L[i]);
      if (it != S.begin()) adj[i].push_back(prev(it)->i);
      if (next(it) != S.end()) adj[next(it)->i].push_back(i);
    } else { // delete
      S.erase(L[i]);
    }
  }

  for (int i=0; i<N; i++) dfs(i);
  reverse(tsort.begin(), tsort.end());

  for (int i=0; i<N; i++) {
    auto [x, y, z, w, _] = L[tsort[i]];
    if (x <= x0 && x0 <= z) x0 = y < w ? x : z;
  }

  cout << x0 << endl;

  ////////////////////////////////
  return 0;
}
