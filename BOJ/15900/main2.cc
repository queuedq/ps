#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 5e5+5;
int N;
vector<int> adj[MAXN];
bool ans = false;

void dfs(int u, int p, bool odd) {
  int cnt = 0;
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u, !odd);
    cnt++;
  }
  if (cnt == 0) ans = ans ^ odd;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1, 0, false);
  cout << (ans ? "Yes" : "No") << endl;

  ////////////////////////////////
  return 0;
}
