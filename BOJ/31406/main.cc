#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, Q, fold[MN];
vector<int> adj[MN], L;

void dfs(int u) {
  for (auto v: adj[u]) {
    L.push_back(v);
    if (!fold[v]) dfs(v);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> Q;
  for (int u=1; u<=N; u++) {
    int d; cin >> d;
    for (int i=0; i<d; i++) {
      int v; cin >> v;
      adj[u].push_back(v);
    }
    fold[u] = u > 1;
  }

  // get list
  dfs(1);

  // query
  int x = 0;
  for (int q=0; q<Q; q++) {
    string t; cin >> t;
    if (t == "move") {
      int k; cin >> k;
      x = min(max(x+k, 0), sz(L)-1);
      cout << L[x] << endl;
    } else {
      fold[L[x]] ^= 1;
      L.clear();
      dfs(1);
    }
  }

  ////////////////////////////////
  return 0;
}
