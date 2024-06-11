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
int N, M, vst[MN], cnt[MN];
vector<int> adj[MN], T[MN];
vector<int> P, L, R;

void dfs(int u) {
  vst[u] = 1;
  cnt[u] = 1;

  for (int v: adj[u]) {
    if (vst[v]) continue;
    dfs(v);
    cnt[u] += cnt[v];
    T[u].push_back(v);
  }
}

void assign_child(int u, vector<int> &vec) {
  vec.push_back(u);
  for (auto v: T[u]) assign_child(v, vec);
}

void get_path(int u, int diff) { // diff = left - right
  P.push_back(u);

  int sum = 0, nxt = 0;
  for (auto v: T[u]) {
    int lsum = diff + sum;
    int rsum = (cnt[u]-1) - sum;

    if (lsum + cnt[v] <= rsum - cnt[v]) assign_child(v, L);
    else if (lsum >= rsum) assign_child(v, R);
    else nxt = v; // continue path
    sum += cnt[v];
  }

  if (nxt) get_path(nxt, sz(L) - sz(R));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1);
  get_path(1, 0);

  cout << sz(P) << " " << sz(L) << endl;
  for (auto u: P) { cout << u << " "; } cout << endl;
  if (sz(L)) {
    for (auto u: L) { cout << u << " "; } cout << endl;
    for (auto u: R) { cout << u << " "; } cout << endl;
  }

  ////////////////////////////////
  return 0;
}
