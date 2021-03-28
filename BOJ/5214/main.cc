#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 100'005;
const int MAXM = 1'000;
int N, K, M, dst[MAXN+MAXM];
vector<int> adj[MAXN+MAXM];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K >> M;
  for (int i=1; i<=M; i++) {
    for (int j=1; j<=K; j++) {
      int x; cin >> x;
      adj[N+i].push_back(x);
      adj[x].push_back(N+i);
    }
  }

  fill(dst, dst+N+M+1, -1);
  dst[1] = 0;

  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto v: adj[u]) {
      if (dst[v] != -1) continue;
      dst[v] = dst[u]+1;
      q.push(v);
    }
  }

  if (dst[N] == -1) cout << -1 << endl;
  else cout << dst[N]/2 + 1 << endl;

  ////////////////////////////////
  return 0;
}
