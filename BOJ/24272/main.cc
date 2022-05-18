#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<17;
int N, Q, in[ST], out[ST], dfn=-1;
int seg[ST*2][2], dir[ST];
vector<int> adj[ST];

struct Edge {
  int u, v, d;
};
vector<Edge> qry;

int get_dir(string S) {
  if (S == "->") return 1;
  if (S == "<-") return -1;
  return 0;
}

void dfs(int u, int p) {
  in[u] = ++dfn;
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
  out[u] = dfn;
}

void update(int n, int nl, int nr, int l, int r, int v) {
  if (r < nl || nr < l) return;
  if (l <= nl && nr <= r) {
    seg[n][0] += v;
  } else {
    int m = (nl+nr+1)/2;
    update(n*2, nl, m-1, l, r, v);
    update(n*2+1, m, nr, l, r, v);
  }
  if (seg[n][0] != 0) seg[n][1] = nr-nl+1;
  else if (n < ST) seg[n][1] = seg[n*2][1] + seg[n*2+1][1];
  else seg[n][1] = 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v, d; string s; cin >> u >> s >> v; d = get_dir(s);
    adj[u].push_back(v);
    adj[v].push_back(u);
    qry.push_back({u, v, d});
  }
  cin >> Q;
  for (int i=0; i<Q; i++) {
    int u, v, d; string s; cin >> u >> s >> v; d = get_dir(s);
    qry.push_back({u, v, d});
  }

  dfs(1, 0);

  for (int i=0; i<N-1+Q; i++) {
    auto [u, v, d] = qry[i];
    if (in[u] < in[v]) { swap(u, v); d = -d; } // par[u] = v
    
    if (dir[u] == -1) {
      update(1, 0, ST-1, in[u], out[u], -1);
    }
    if (dir[u] == 1) {
      update(1, 0, ST-1, 0, in[u]-1, -1);
      update(1, 0, ST-1, out[u]+1, N-1, -1);
    }

    if (d == -1) {
      update(1, 0, ST-1, in[u], out[u], 1);
    }
    if (d == 1) {
      update(1, 0, ST-1, 0, in[u]-1, 1);
      update(1, 0, ST-1, out[u]+1, N-1, 1);
    }

    dir[u] = d;
    if (i >= N-1) cout << (N - seg[1][1]) << endl;
  }

  ////////////////////////////////
  return 0;
}
