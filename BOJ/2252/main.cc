#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 32'005;
int N, M, vst[MAXN], rst[MAXN];
vector<int> adj[MAXN];

void dfs(int u, int &cnt) {
  if (vst[u]) return;
  for (auto v: adj[u]) {
    dfs(v, cnt);
  }
  vst[u] = ++cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
  }

  int cnt = 0;
  for (int i=1; i<=N; i++) dfs(i, cnt);
  for (int i=1; i<=N; i++) rst[vst[i]] = i;

  for (int i=N; i>=1; i--) cout << rst[i] << endl;

  ////////////////////////////////
  return 0;
}
