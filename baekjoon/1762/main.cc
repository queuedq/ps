#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, M;
set<int> adj[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  int cnt = 0;
  for (int i=0; i<M; i++) {
    int a, b; cin >> a >> b;
    adj[a].insert(b);
    adj[b].insert(a);
    if (adj[a].size() > adj[b].size()) swap(a, b);
    for (auto x: adj[a]) {
      if (adj[b].find(x) != adj[b].end()) cnt++;
    }
  }
  cout << cnt << endl;

  ////////////////////////////////
  return 0;
}
