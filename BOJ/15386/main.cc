#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 105;
const int MC = 101010;
int N, C, par[MN];

struct Edge {
  lld a, b, r;
  bool operator <(const Edge &E) const { return r < E.r; }
};

int find(int x) {
  return x == par[x] ? x : par[x] = find(par[x]);
}

void solve(int test) {
  cin >> N >> C;
  vector<Edge> E(C);
  for (int i=0; i<C; i++) {
    lld a, b, r; cin >> a >> b >> r;
    E[i] = {a, b, r};
  }
  reverse(all(E));

  vector<Edge> mst;
  vector<lld> ans;
  for (int i=0; i<C; i++) {
    mst.push_back(E[i]);
    sort(all(mst));

    iota(par, par+N+1, 0);
    vector<Edge> new_mst;

    for (auto [a, b, r]: mst) {
      a = find(a), b = find(b);
      if (a == b) continue;
      par[b] = a;
      new_mst.push_back({a, b, r});
    }

    mst = new_mst;
    if (sz(mst) < N-1) {
      ans.push_back(-1);
    } else {
      lld cost = 0;
      for (auto [a, b, r]: mst) cost += r;
      ans.push_back(cost);
    }
  }

  reverse(all(ans));

  cout << "Case #" << test << ":" << endl;
  for (auto a: ans) {
    if (a == -1) cout << "FAIL" << endl;
    else cout << a << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
