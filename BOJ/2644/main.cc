#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 105;
int N, M, a, b, dst[MN];
vector<int> adj[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> a >> b >> M;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  fill_n(dst+1, N, -1);
  queue<int> Q;
  dst[a] = 0;
  Q.push(a);

  while (!Q.empty()) {
    int u = Q.front(); Q.pop();

    for (int v: adj[u]) {
      if (dst[v] != -1) continue;
      dst[v] = dst[u] + 1;
      Q.push(v);
    }
  }

  cout << dst[b] << endl;

  ////////////////////////////////
  return 0;
}
