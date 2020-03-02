#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 2005;
int N, visited[MAXN];
vector<int> adj[MAXN];

pii dfs(int u, bool p) {
  if (visited[u]) return {0, 0};
  visited[u] = true;
  int o=0, e=0;
  if (p) o++;
  else e++;

  for (auto v: adj[u]) {
    auto [oo, ee] = dfs(v, !p);
    o += oo;
    e += ee;
  }

  return {o, e};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    string s; cin >> s;
    for (int j=0; j<s.size(); j++) {
      if (s[j] == '1') {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }

  int ans = 0;
  for (int i=0; i<N; i++) {
    auto [o, e] = dfs(i, true);
    ans += max(o, e);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
