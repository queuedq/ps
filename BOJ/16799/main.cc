#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9;
const int MN = 101010;
int N, P[MN];
vector<int> adj[MN];
map<pii, pii> D[MN]; // (u, a, b) -> (min, max) calculations

int minimax(int u) {
  if (adj[u].empty()) return P[u];

  P[u] = -INF;
  for (auto v: adj[u]) {
    int val = -minimax(v);
    P[u] = max(P[u], val);
  }
  return P[u];
}

pii dp(int u, int a, int b) { // returns (min, max) calculations
  if (D[u].count({a, b})) return D[u][{a, b}];
  if (a >= b) return D[u][{a, b}] = {0, 0};
  if (adj[u].empty()) return D[u][{a, b}] = {1, 1};

  auto &[ans_mn, ans_mx] = D[u][{a, b}] = {INF, -INF};

  int a_tmp = a, b_tmp = b;

  sort(all(adj[u]));
  do { // test all permutations
    int a = a_tmp, b = b_tmp;
    int tot_mn = 0, tot_mx = 0;

    for (auto v: adj[u]) {
      auto [cnt_mn, cnt_mx] = dp(v, -b, -a);
      tot_mn += cnt_mn;
      tot_mx += cnt_mx;
      int val = -P[v];
      if (val >= b) break;
      if (val > a) a = val;
    }

    ans_mn = min(ans_mn, tot_mn);
    ans_mx = max(ans_mx, tot_mx);

  } while(next_permutation(all(adj[u])));

  return {ans_mn, ans_mx};
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> P[i];
  for (int u=1; u<=N; u++) {
    int k; cin >> k;
    for (int j=1; j<=k; j++) {
      int t; cin >> t;
      adj[u].push_back(t);
    }
  }

  minimax(1);
  auto [mn, mx] = dp(1, -INF, INF);

  cout << mn << " " << mx << endl;

  ////////////////////////////////
  return 0;
}
