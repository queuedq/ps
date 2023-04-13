#include <bits/stdc++.h>
#include <initializer_list>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<18;
int N, Q, vst[ST], rnk[3][ST], comp[ST];
vector<int> ord;

struct Segtree {
  pii seg[ST*2];

  void update(int i, pii v) {
    seg[i+=ST] = v;
    for (i/=2; i>0; i/=2) seg[i] = min(seg[i*2], seg[i*2+1]);
  }

  pii query(int l, int r) {
    pii ans = {INT_MAX, 0};
    for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
      if (l&1) ans = min(ans, seg[l++]);
      if (r&1) ans = min(ans, seg[--r]);
    }
    return ans;
  }
} seg[3];

void dfs(int u) {
  if (vst[u]) return;
  vst[u] = 1;
  for (int i=0; i<3; i++) seg[i].update(rnk[i][u], {INT_MAX, 0});

  for (int i=0, j=1; i<3; ++i, ++j%=3) {
    while (1) {
      auto [r, v] = seg[i].query(0, rnk[i][u]-1);
      if (r > rnk[j][u]) break; // no edges
      dfs(v);
    }
  }

  ord.push_back(u);
}

void scc(int u, int c) {
  if (comp[u]) return;
  comp[u] = c;
  for (int i=0; i<3; i++) seg[i].update(rnk[i][u], {INT_MAX, 0});

  for (int i=0, j=1; i<3; ++i, ++j%=3) {
    while (1) {
      auto [r, v] = seg[i].query(0, rnk[i][u]-1);
      if (r > rnk[j][u]) break; // no edges
      scc(v, c);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    for (int j=0; j<3; j++) cin >> rnk[j][i];
  }

  // forward
  for (int i=0, j=1; i<3; ++i, ++j%=3) {
    for (int u=1; u<=N; u++) seg[i].update(rnk[i][u], {rnk[j][u], u});
  }

  for (int u=1; u<=N; u++) dfs(u);
  reverse(all(ord));

  // backward
  for (int i=0; i<3; i++) {
    for (int u=1; u<=N; u++) rnk[i][u] = N+1-rnk[i][u];
  }
  for (int i=0, j=1; i<3; ++i, ++j%=3) {
    for (int u=1; u<=N; u++) seg[i].update(rnk[i][u], {rnk[j][u], u});
  }

  int c = 1;
  for (auto u: ord) {
    if (!comp[u]) scc(u, c++);
  }

  // for (int u=1; u<=N; u++) cout << comp[u] << " "; cout << endl;

  cin >> Q;
  for (int i=0; i<Q; i++) {
    int u, v; cin >> u >> v;
    cout << (comp[u] >= comp[v] ? "YES" : "NO") << endl;
  }

  ////////////////////////////////
  return 0;
}
