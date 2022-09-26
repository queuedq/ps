#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 10101;
int N, M, T[MN], vst[MN];
vector<int> adj[MN];

bool match(int u) {
  if (vst[u]) return 0;
  vst[u] = 1;
  for (auto v: adj[u]) {
    if (!T[v] || match(T[v])) { T[v] = u; return 1; }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
  }

  int cnt = 0;
  for (int u=1; u<=N; u++) {
    fill(vst+1, vst+N+1, 0);
    cnt += match(u);
  }
  cout << N - cnt << endl;

  ////////////////////////////////
  return 0;
}
