#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<18;
int N, M, w[ST], ans, U, V;
vector<int> adj[ST];
vector<pii> anc[ST], des[ST], nei[ST]; // u -> {v, w}

int in[ST], out[ST], ord[ST], idx, lazy[ST*2];
pii seg[ST*2];

void push(int n) {
  seg[n*2].first += lazy[n];
  seg[n*2+1].first += lazy[n];
  lazy[n*2] += lazy[n];
  lazy[n*2+1] += lazy[n];
  lazy[n] = 0;
}

void add(int n, int nl, int nr, int l, int r, int x) {
  if (nr < l || r < nl) return;
  if (l <= nl && nr <= r) { seg[n].first += x; lazy[n] += x; return; }
  push(n);
  int m = (nl+nr)/2;
  add(n*2, nl, m, l, r, x);
  add(n*2+1, m+1, nr, l, r, x);
  seg[n] = max(seg[n*2], seg[n*2+1]);
}
void add(int l, int r, int x) { add(1, 0, ST-1, l, r, x); }

void euler(int u, int p) {
  ord[idx] = u;
  in[u] = idx++;
  for (int i=0; i<adj[u].size(); i++) { // make adj[u] sorted
    if (adj[u][i] == p) { swap(adj[u][0], adj[u][i]); break; }
  }
  for (auto v: adj[u]) {
    if (v != p) euler(v, u);
  }
  out[u] = idx-1;
}

bool cmp(int u, int v) { return in[u] < in[v]; }

bool ancestor(int u, int v) { return in[u] <= in[v] && out[v] <= out[u]; }

void dfs(int u, int p) {
  for (auto [v, w]: anc[u]) add(0, N-1, w), add(in[v], out[v], -w);
  for (auto [v, w]: des[u]) add(in[v], out[v], -w);
  for (auto [v, w]: nei[u]) add(in[v], out[v], w);
  if (seg[1].first > ans) U = u, V = ord[seg[1].second], ans = seg[1].first;

  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u);
  }

  for (auto [v, w]: anc[u]) add(0, N-1, -w), add(in[v], out[v], +w);
  for (auto [v, w]: des[u]) add(in[v], out[v], w);
  for (auto [v, w]: nei[u]) add(in[v], out[v], -w);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  euler(1, 0);
  for (int i=0; i<N; i++) seg[ST+i] = {0, i};

  cin >> M;
  for (int i=0; i<M; i++) {
    int a, b, w; cin >> a >> b >> w;
    if (in[a] > in[b]) swap(a, b);
    if (ancestor(a, b)) {
      int c = *prev(upper_bound(all(adj[a]), b, cmp));
      des[c].push_back({b, w});
      anc[b].push_back({c, w});
      add(in[b], out[b], w);
    } else {
      nei[a].push_back({b, w});
      nei[b].push_back({a, w});
    }
  }

  U = 1, V = ord[seg[1].second], ans = seg[1].first;
  dfs(1, 0);
  cout << U << " " << V << " " << ans << endl;

  ////////////////////////////////
  return 0;
}
