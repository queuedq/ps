#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
int N, M;
vector<int> adj[MAXN];
bool vst[MAXN];

void dfs(int u) {
  if (vst[u]) return;
  vst[u] = true;
  for (auto v: adj[u]) dfs(v);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int cnt = 0;
  for (int i=1; i<=N; i++) {
    if (vst[i]) continue;
    dfs(i);
    cnt++;
  }

  cout << cnt << endl;

  ////////////////////////////////
  return 0;
}
