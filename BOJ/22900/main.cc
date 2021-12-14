#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
int N, D[MN], E[MN];
// D[u]: # of losing subtrees (= winning edges)
// E[u]: wins if go up
vector<int> adj[MN];

int dp(int u, int p) {
  for (auto v: adj[u]) {
    if (v == p) continue;
    D[u] += dp(v, u) == 0;
  }
  return D[u];
}

void dp2(int u, int p) {
  if (!E[p] && D[p] - (D[u] == 0) == 0) E[u] = true;

  for (auto v: adj[u]) {
    if (v == p) continue;
    dp2(v, u);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int x, y, a; cin >> x >> y >> a;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  E[0] = true;
  dp(1, 0);
  dp2(1, 0);

  for (int u=1; u<=N; u++) {
    if (D[u] > 0 || E[u]) cout << "Zeze" << endl;
    else cout << "Portuga" << endl;
  }

  ////////////////////////////////
  return 0;
}
