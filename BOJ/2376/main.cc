#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
int N, A, B, dst[MN], nxt[MN], prv[MN], root[MN], D[MN*2];
vector<int> adj[MN*2];

void make_edge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void dfs(int u, int p, int d) {
  D[u] = d;
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u, d+1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N-1; i++) cin >> dst[i];
  cin >> A >> B;

  for (int i=1; i<=N; i++) {
    nxt[i] = i+1;
    prv[i] = i-1;
    root[i] = i;
  }

  for (int i=1; i<=N-1; i++) {
    // find dst 2 nodes
    int u = 0, v = 0;
    for (int x=1; nxt[x]<=N; x=nxt[x]) {
      if (dst[x] == 2) { u = x; break; }
    }
    v = nxt[u];
    // assert(u != 0);

    // merge two trees
    make_edge(root[u], N+i);
    make_edge(root[v], N+i);
    root[u] = root[v] = N+i;
    nxt[u] = nxt[v];
    prv[nxt[u]] = u;

    // update dst
    dst[prv[u]]--;
    dst[u] = dst[v] - 1;
  }

  dfs(A, 0, 0);
  cout << D[B] << endl;

  ////////////////////////////////
  return 0;
}
