#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, M, a, b, par[MN], on[MN], len[MN];
vector<int> adj[MN];
vector<int> C; // lengths on path

void dfs(int u, int p) {
  par[u] = p;
  on[u] = u == b;

  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    if (on[v]) on[u] = 1;
    else len[u] = max(len[u], len[v]+1);
  }
}

int solve(int l, int r, bool turn) {
  static int L = 0, R = 0; // max path length in [l, r] (right before return)

  if (l+1 == r) {
    int score = (C[l] + l) - (C[r] + M-r-1);
    L = max(C[l] + l, C[r] + r);
    R = max(C[l] + M-l-1, C[r] + M-r-1);
    return turn ? score : -score;
  }

  if (turn) {
    int score = -solve(l+1, r, !turn);
    score = max(score, (C[l] + l) - R);
    L = max(L, C[l] + l);
    R = max(R, C[l] + M-l-1);
    return score;
  } else {
    int score = -solve(l, r-1, !turn);
    score = max(score, (C[r] + M-r-1) - L);
    L = max(L, C[r] + r);
    R = max(R, C[r] + M-r-1);
    return score;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> a >> b;
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(a, 0);
  for (int u=b; u!=0; u=par[u]) C.push_back(len[u]);
  reverse(all(C));

  M = sz(C);
  int ans = solve(0, M-1, 1);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
