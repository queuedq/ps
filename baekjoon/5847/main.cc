#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 10005;
int N, M, T[MAXN];
vector<int> adj[MAXN];
bool vst[MAXN];
int D[MAXN];

int dfs(int u) {
  if (vst[u]) return D[u];
  vst[u] = true;

  int d = 0;
  for (auto v: adj[u]) {
    d = max(d, dfs(v));
  }
  return D[u] = d + T[u];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) cin >> T[i];
  for (int i=1; i<=M; i++) {
    int a, b; cin >> a >> b;
    adj[b].push_back(a);
  }

  int ans = 0;
  for (int i=1; i<=N; i++) {
    ans = max(ans, dfs(i));
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
