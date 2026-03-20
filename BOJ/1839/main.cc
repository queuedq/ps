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
int N;
vector<int> adj[MN];
int D[MN]; // open path length

bool dfs(int u, int p, int mx) {
  multiset<int> S;
  if (sz(adj[u]) % 2 == 1) S.insert(0); // endpoint at odd vertex

  for (auto v: adj[u]) {
    if (v == p) continue;
    if (!dfs(v, u, mx)) return false;
    if (D[v]+1 > mx) return false;
    S.insert(D[v]+1);
  }

  // matching
  while (sz(S) > 1) {
    // match the longest in S...
    auto it = prev(S.end());
    auto d = *it;
    S.erase(it);

    // ...with another longest matchable (d+e <= mx)
    it = S.upper_bound(mx-d);
    if (it == S.begin()) return false; // no match
    S.erase(prev(it));
  }

  if (p != 0) D[u] = *S.begin();
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // count paths
  int cnt = 0;
  for (int i=1; i<=N; i++) cnt += sz(adj[i]) % 2;
  cnt /= 2;

  // solve
  int l = 0, r = N-1;
  while (l+1 < r) {
    int m = (l+r)/2;
    if (dfs(1, 0, m)) r = m;
    else l = m;
  }

  // print ans
  cout << cnt << " " << r << endl;

  ////////////////////////////////
  return 0;
}
