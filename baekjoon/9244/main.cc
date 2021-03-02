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

const lld INF = 1e9;
const int MN = 1e5+5;
int N, x0;
Line L[MN];
vector<pair<pll, int>> E;
set<Line> S;
int nxt[MN];

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
  L[N] = {x0, INF, x0+1, INF+1};
  E.push_back({{x0, 0}, N});
  E.push_back({{x0, 1}, N});

  sort(E.begin(), E.end());

  fill(nxt, nxt+N+1, -1);
  for (auto [e, i]: E) {
    auto [x, type] = e;
    if (type == 0) { // insert
      auto [it, _] = S.insert(L[i]);
      if (it != S.begin() && L[i].y < L[i].w) nxt[i] = prev(it)->i;
    } else { // delete
      auto it = S.find(L[i]);
      if (it != S.begin() && L[i].y > L[i].w) nxt[i] = prev(it)->i;
      S.erase(L[i]);
    }
  }

  int k = N;
  while (nxt[k] != -1) k = nxt[k];

  cout << (L[k].y < L[k].w ? L[k].x : L[k].z) << endl;

  ////////////////////////////////
  return 0;
}
