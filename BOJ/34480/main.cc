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
int N, M;
int par[MN*2], cnt[MN*2]; // cnt = # distinct vertices
vector<int> comp[MN*2];
unordered_map<lld, int> inter; // # elements in intersection of two components

lld sorted_pair(int a, int b) {
  if (a > b) swap(a, b);
  return (lld)a << 32 | b;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;

  // init disjoint set
  for (int i=0; i<N*2; i++) {
    par[i] = i;
    cnt[i] = 1;
    comp[i].push_back(i);
    if (i%2 == 0) inter[sorted_pair(i, i^1)] = 1;
  }

  // solve
  lld sum1 = 0; // # pairs in component
  lld sum2 = 0; // # pairs in intersection of two components

  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    u = (u-1)*2, v = (v-1)*2+1;

    u = par[u], v = par[v]; // don't need find() because we directly set parents
    if (u == v) {
      cout << sum1 - sum2 << endl;
      continue;
    }
    if (sz(comp[u]) < sz(comp[v])) swap(u, v);

    // update sum1
    int both = 0;
    for (int x: comp[v]) both += par[x^1] == u;
    sum1 -= (lld)cnt[u] * (cnt[u]-1) / 2;
    sum1 -= (lld)cnt[v] * (cnt[v]-1) / 2;
    cnt[u] += cnt[v] - both;
    sum1 += (lld)cnt[u] * (cnt[u]-1) / 2;

    // merge
    for (int x: comp[v]) {
      // containing sets
      int w = par[x^1];
      lld a = sorted_pair(v, w);
      lld b = sorted_pair(u, w);

      // update sum2
      if (v != w) inter[a]--, sum2 -= inter[a];
      if (u != w) sum2 += inter[b], inter[b]++;

      // merge directly
      par[x] = u;
      comp[u].push_back(x);
    }
    comp[v].clear();

    cout << sum1 - sum2 << endl;
  }

  ////////////////////////////////
  return 0;
}
