#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1'000'000'007;
const int MN = 2005;
int N, M, par[MN], pow3[MN];
vector<pii> edges;

int find(int x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}

void merge(int x, int y) {
  x = find(x), y = find(y);
  par[y] = x;
}

bool connects(int x, int y) {
  x = find(x), y = find(y);
  int s = find(0), t = find(N-1);
  return (s == x && t == y) || (s == y && t == x);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    edges.push_back({u, v});
  }

  for (int i=0; i<N; i++) par[i] = i;
  pow3[0] = 1;
  for (int i=1; i<M; i++) pow3[i] = pow3[i-1] * 3LL % MOD;

  lld ans = 0;
  for (int i=M-1; i>=0; i--) {
    auto [u, v] = edges[i];
    if (connects(u, v)) ans = (ans + pow3[i]) % MOD;
    else merge(u, v);
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
