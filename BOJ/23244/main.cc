#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

struct Line {
  lld x1, y1, x2, y2, i; // y1 < y2

  double f(double y) const {
    if (y1 == y2) return x1;
    return (y-y1) * (x2-x1) / (y2-y1) + x1;
  }

  bool operator <(const Line &L) const {
    lld y = max(y1, L.y1);
    return f(y) < L.f(y);
  }
};

const int MN = 20202;
int N, D[MN], vst[MN];
Line L[MN];
set<Line> S;
vector<pll> E;
vector<int> adj[MN];

void dfs(int u) {
  if (vst[u]) return;
  vst[u] = true;
  D[u] = 1;

  for (auto v: adj[u]) {
    dfs(v);
    D[u] = max(D[u], D[v] + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    lld x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    if (y1 > y2) { swap(x1, x2); swap(y1, y2); }
    L[i] = {x1, y1, x2, y2, i};

    E.push_back({L[i].y1, -i}); // insert first
    E.push_back({L[i].y2, i}); // remove last
  }
  sort(E.begin(), E.end());

  for (auto [y, i]: E) {
    if (i < 0) {
      i = -i;
      S.insert(L[i]);
      auto it = S.lower_bound(L[i]);
      if (it != S.begin()) adj[prev(it)->i].push_back(i);
      if (next(it) != S.end()) adj[i].push_back(next(it)->i);
    } else {
      S.erase(L[i]);
    }
  }

  int ans = 0;
  for (int i=1; i<=N; i++) {
    // cout << i << endl;
    // for (auto v: adj[i]) cout << v << " "; cout << endl;
    dfs(i);
    ans = max(ans, D[i]);
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
