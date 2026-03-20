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

struct Edge {
  int x, y, w;
  bool operator <(Edge E) const { return w < E.w; }
};

int N, M, K, C[MN], par[MN];
vector<Edge> E;
map<int, int> S[MN];
lld ans[MN];

int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K >> M;
  for (int i=1; i<=N; i++) {
    cin >> C[i];
    par[i] = i;
    S[i][C[i]] = 1;
  }
  for (int i=0; i<M; i++) {
    int x, y, w; cin >> x >> y >> w;
    E.push_back({x, y, w});
  }
  sort(all(E));
  reverse(all(E));

  for (auto [x, y, w]: E) {
    x = find(x), y = find(y);
    if (x == y) continue;
    if (sz(S[x]) < sz(S[y])) swap(x, y);

    for (auto [c, cnt]: S[y]) {
      ans[c] += (lld)S[x][c] * cnt * w;
    }

    par[y] = x;
    for (auto [c, cnt]: S[y]) S[x][c] += cnt;
    S[y].clear();
  }

  for (int i=1; i<=K; i++) cout << ans[i] << endl;

  ////////////////////////////////
  return 0;
}
