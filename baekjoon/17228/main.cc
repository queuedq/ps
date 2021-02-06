#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 500'005;
int N, fail[MN], match[MN], nxt[26][MN], ans;
vector<pii> adj[MN];
string P;

int get_fail(int j, int c) {
  if (nxt[c-'a'][j] != -1) return nxt[c-'a'][j];

  if (j > 0 && c != P[j]) return nxt[c-'a'][j] = get_fail(fail[j-1], c);
  return nxt[c-'a'][j] = j;
}

void dfs(int u, int p, int c) {
  int j = match[p];
  if (j == P.size()) j = fail[j-1];
  j = get_fail(j, c);

  if (c == P[j]) match[u] = ++j;
  else match[u] = 0;

  if (match[u] == P.size()) ans++;

  for (auto [v, d]: adj[u]) dfs(v, u, d);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v; char c; cin >> u >> v >> c;
    adj[u].push_back({v, c});
  }

  cin >> P;
  
  for (int i=1, j=0; i<P.size(); i++) {
    while (j > 0 && P[i] != P[j]) j = fail[j-1];
    if (P[i] == P[j]) fail[i] = ++j;
  }

  for (int i=0; i<26; i++) fill(nxt[i], nxt[i]+P.size(), -1);
  for (auto [u, c]: adj[1]) dfs(u, 1, c);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
