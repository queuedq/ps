#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 2e5+5;
const int INF = 1e9;
int N, M, D[MAXN][3]; // 0: selected, 1: !selected && covered, 2: !selected && !covered
bool visited[MAXN];
vector<int> adj[MAXN];

int min(int a, int b, int c) {
  return min(min(a, b), c);
}

int dp(int u, int p) {
  if (visited[u]) return 0;
  visited[u] = true;

  D[u][0] = 1;
  for (auto v: adj[u]) {
    if (v == p) continue;
    dp(v, u);
    D[u][0] += min(D[v][0], D[v][1], D[v][2]);
    D[u][1] += min(D[v][0], D[v][1]);
    D[u][2] = min(INF, D[u][2] + D[v][1]);
  }

  int delta = INF;
  for (auto v: adj[u]) {
    if (v == p) continue;
    delta = min(delta, D[v][0] - min(D[v][0], D[v][1]));
  }
  D[u][1] = min(INF, D[u][1] + delta);

  return min(D[u][0], D[u][1]);
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

  int ans = 0;
  for (int i=1; i<=N; i++) {
    ans += dp(i, -1);
  }

  // for (int i=1; i<=N; i++) {
  //   cout << D[i][0] << " " << D[i][1] << " " << D[i][2] << endl;
  // }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
