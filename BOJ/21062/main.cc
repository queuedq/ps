#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N1, M1, N2, M2, par[2][MN];

int find(int g, int x) {
  if (par[g][x] == x) return x;
  return par[g][x] = find(g, par[g][x]);
}

struct Edge {
  lld g, u, v, w;
  bool operator <(const Edge &E) const { return w < E.w; }
};
vector<Edge> E;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N1 >> M1 >> N2 >> M2;
  for (int i=0; i<M1; i++) {
    lld u, v, w; cin >> u >> v >> w;
    E.push_back({0, u, v, w});
  }
  for (int i=0; i<M2; i++) {
    lld u, v, w; cin >> u >> v >> w;
    E.push_back({1, u, v, w});
  }
  sort(all(E));

  iota(par[0], par[0]+N1+1, 0);
  iota(par[1], par[1]+N2+1, 0);

  lld ans = 0;
  for (auto [g, u, v, w]: E) {
    int a = find(g, u), b = find(g, v);
    if (a == b) continue;
    par[g][b] = a;
    
    if (g == 0) { ans += w * N2; N1--; }
    else { ans += w * N1; N2--; }
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
