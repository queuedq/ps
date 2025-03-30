#include <algorithm>
#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e8;
const int MN = 505;
int N, K, ord[MN], used[MN], vst[MN], deg[MN];
vector<int> adj[MN];
int D[MN][2]; // num paths, 0: ends at u, 1: goes above u

void dp(int u, int p) {
  vst[u] = 1;
  int sum = 0, mn = INF, mn2 = INF;

  for (auto v: adj[u]) {
    if (v == p || used[v]) continue;
    dp(v, u);

    sum += D[v][0];
    int delta = D[v][1] - D[v][0];
    if (delta < mn) mn2 = mn, mn = delta;
    else if (delta < mn2) mn2 = delta;
  }

  D[u][0] = min({sum+1, sum+mn, sum+mn+mn2-1}); // 0, 1, 2 edges to children
  D[u][1] = min({sum+1, sum+mn}); // 0, 1 edges to children
}

bool check_adj(int u, int v) {
  for (auto x: adj[u]) if (x == v) return true;
  return false;
}

bool check_star(int size) {
  if (size == 1) return false;
  int mx = 0;
  for (int u=1; u<=N; u++) if (!used[u]) {
    mx = max(mx, deg[u]);
  }
  return mx == size - 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++, deg[v]++;
  }

  int jumps = 0;
  for (int i=1; i<=N; i++) {
    for (int s=1; s<=N; s++) if (!used[s]) {
      // check jump from previous node
      bool is_adj = check_adj(ord[i-1], s);
      if (i == 1) is_adj = 1;

      // get lower bound
      fill_n(vst+1, N, 0);
      dp(s, 0);
      int paths = D[s][1];
      for (int u=1; u<=N; u++) if (!used[u] && !vst[u]) {
        dp(u, 0);
        paths += D[u][0];
      }

      int l = jumps + !is_adj + (paths - 1);

      // get upper bound
      bool is_star = check_star(N-i+1); // star containing s

      used[s] = 1; for (auto v: adj[s]) deg[v]--;
      bool is_rest_star = check_star(N-i); // star excluding s
      used[s] = 0; for (auto v: adj[s]) deg[v]++;

      paths = (N-i+1) - (is_star || is_rest_star);

      int r = jumps + !is_adj + (paths - 1);

      // check possible
      if (l <= K && K <= r) {
        ord[i] = s;
        used[s] = 1;
        for (auto v: adj[s]) deg[v]--;
        jumps += !is_adj;
        break;
      }
    }

    if (!ord[i]) { assert(i == 1); break; }
  }

  if (!ord[1]) {
    cout << -1 << endl;
  } else {
    for (int i=1; i<=N; i++) cout << ord[i] << " ";
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
