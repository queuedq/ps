#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;
int N, M, dst[MN];
vector<int> adj[MN];

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
  fill(dst+1, dst+N+1, -1);

  queue<int> Q;
  Q.push(1);
  dst[1] = 0;
  int cnt = 1, mx = 0;

  while (!Q.empty()) {
    auto u = Q.front(); Q.pop();
    for (auto v: adj[u]) {
      if (dst[v] == -1) {
        Q.push(v);
        dst[v] = dst[u]+1;
        cnt++;
        mx = max(mx, dst[v]);
      }
    }
  }

  if (cnt < N) cout << -1 << endl;
  else cout << (int)ceil(log2(mx))+1 << endl;

  ////////////////////////////////
  return 0;
}
