#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 2e5+5;
const int INF = 1e9;
int N, M;
bool D[MAXN], visited[MAXN];
vector<int> adj[MAXN];

int min(int a, int b, int c) {
  return min(min(a, b), c);
}

int dfs(int u, bool root) { // 0: selected, 1: !selected && covered, 2: !selected && !covered
  if (visited[u]) return 0;
  visited[u] = true;

  bool selected = false, covered = false;
  for (auto v: adj[u]) {
    if (visited[v]) continue;
    int t = dfs(v, false);
    if (t == 0) covered = true;
    if (t == 2) selected = true;
  }

  if (selected) {
    D[u] = true;
    return 0;
  }
  if (covered) return 1;
  if (root) D[u] = true;
  return 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=M; i++) {
    int A, B; cin >> A >> B;
    adj[A].push_back(B); adj[B].push_back(A);
  }

  for (int i=1; i<=N; i++) dfs(i, true);

  int ans = 0;
  for (int i=1; i<=N; i++) ans += D[i];
  // for (int i=1; i<=N; i++) cout<<D[i] << endl;

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
