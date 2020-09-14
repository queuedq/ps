#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 3e6+5;
int N;
vector<int> adj[MAXN];

int dfs(int u, int p, int g, bool &ok) {
  if (!ok) return 0;
  int size = 1;
  for (auto v: adj[u]) {
    if (v == p) continue;
    size += dfs(v, u, g, ok);
  }
  if (size > g) { ok = false; return 0; }
  return size % g;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N-1; i++) {
    int a; cin >> a;
    adj[i+1].push_back(a);
    adj[a].push_back(i+1);
  }

  for (int k=1; k<=N; k++) {
    if (N % k) continue;
    bool ok = true;
    dfs(1, 0, N/k, ok);
    if (ok) cout << k << " ";
  }
  cout << endl;

  ////////////////////////////////
  return 0;
}
