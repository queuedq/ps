#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 250'005;
lld N, X; // X: possible empty rooms
int ant[MN], num[MN]; // num: ants in child nodes
vector<int> adj[MN];

void dfs(int u, int p) {
  ant[u] = 1;
  num[u] = 0;

  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    num[u] += ant[v];
  }
  ant[u] = num[u] == 0;
}

void reroot(int u, int p) {
  if (!ant[u]) X++;

  for (auto v: adj[u]) {
    if (v == p) continue;

    num[u] -= ant[v], ant[u] = num[u] == 0;
    num[v] += ant[u], ant[v] = num[v] == 0;
    reroot(v, u);
    num[v] -= ant[u], ant[v] = num[v] == 0;
    num[u] += ant[v], ant[u] = num[u] == 0;
  }
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

  dfs(1, 0);
  reroot(1, 0);

  lld Y = N-X; // must be occupied
  cout << (lld)N*(N-1)/2 - (lld)Y*(Y-1)/2 << endl;

  ////////////////////////////////
  return 0;
}
