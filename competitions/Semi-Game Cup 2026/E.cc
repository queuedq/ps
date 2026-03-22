#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
int N, par[MN], D[MN];
vector<int> adj[MN];
char color[MN];

void dfs(int u, int p) {
  for (auto v: adj[u]) {
    if (v == p) continue;
    if (color[v] != 'G') {
      dfs(v, u);
      D[u] += D[v];
    }
  }

  if (color[u] == 'B') {
    D[u]++;
    D[u] = max(D[u], 0);
  } else {
    D[u]--;
    D[u] = min(D[u], 0);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int u=2; u<=N; u++) {
    cin >> par[u];
    adj[par[u]].push_back(u);
  }
  for (int u=1; u<=N; u++) { cin >> color[u]; }

  int score = 0;
  for (int u=2; u<=N; u++) {
    if (color[u] != 'G' && color[par[u]] == 'G') {
      dfs(u, par[u]);
      score += D[u];
    }
  }

  cout << max(score, 0) << endl;

  ////////////////////////////////
  return 0;
}
