#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
#define MAX_N 300005
#define MOD 998244353
int N, M, K;
vector<int> adj[MAX_N];
bool visited[MAX_N];
bool home[MAX_N];
bool office[MAX_N];
lld cnt[MAX_N], dist[MAX_N], sqr[MAX_N];
lld ans;

void input() {
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
    int m; cin >> m;
    home[m] = true;
  }
  cin >> K;
  for (int i = 0; i < K; i++) {
    int k; cin >> k;
    office[k] = true;
  }
}

void dfs1(int c) {
  visited[c] = true;
  cnt[c] = home[c];
  for (int node: adj[c]) {
    if (visited[node]) { continue; }
    dfs1(node);
    cnt[c] += cnt[node];
    dist[c] += dist[node] + cnt[node];
    sqr[c] += sqr[node] + 2 * dist[node] + cnt[node];
  }
}

void dfs2(int c, lld upCnt, lld upDist, lld upSqr) {
  visited[c] = true;
  // cout << "At " << c << ", upcnt: " << upCnt << ", updist: " << upDist << ", upSqr: " << upSqr << endl;
  if (office[c]) {
    ans = (ans + upSqr + sqr[c]) % MOD;
  }

  for (int node: adj[c]) {
    if (visited[node]) { continue; }
    lld newCnt = upCnt + cnt[c] - cnt[node];
    lld newDist = upDist + dist[c] + newCnt - dist[node] - cnt[node];
    lld newSqr = upSqr + sqr[c] + 2 * newDist - newCnt - sqr[node] - 2 * dist[node] - cnt[node];
    dfs2(node, newCnt, newDist, newSqr);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  dfs1(1);
  for (int i = 1; i <= N; i++) {
    visited[i] = false;
  }
  dfs2(1, 0, 0, 0);

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
