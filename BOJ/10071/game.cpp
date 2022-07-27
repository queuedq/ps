#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
#include "game.h"

const int MN = 1505;
int N, par[MN], sz[MN];
int cnt[MN][MN];

int find(int x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}

void merge(int x, int y) {
  if (sz[x] < sz[y]) swap(x, y);
  par[y] = x;
  sz[x] += sz[y];
  
  for (int i=0; i<N; i++) {
    cnt[x][i] = cnt[i][x] = cnt[x][i] + cnt[y][i];
  }
}

void initialize(int n) {
  N = n;
  iota(par, par+N, 0);
  fill(sz, sz+N, 1);
}

int hasEdge(int u, int v) {
  u = find(u), v = find(v);
  // assert(u != v);
  cnt[u][v] = cnt[v][u] = cnt[u][v] + 1;
  if (cnt[u][v] != sz[u] * sz[v]) return 0;
  merge(u, v);
  return 1;
}
