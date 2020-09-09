#include "template.h"

const int MAXN = 50005;
int N;
vector<int> tree[MAXN], centroidTree[MAXN];
int sub[MAXN];
bool dead[MAXN];

int getSize(int u, int p) {
  sub[u] = 1;
  for (auto v: tree[u]) {
    if (v == p || dead[v]) continue;
    sub[u] += getSize(v, u);
  }
  return sub[u];
}

int getCentroid(int u, int p, int n) {
  for (auto v : tree[u]) {
    if (v == p || dead[v]) continue;
    if (sub[v] > n/2) return getCentroid(v, u, n);
  }
  return u;
}

int centroidDecomp(int u) {
  int n = getSize(u, -1);
  int c = getCentroid(u, -1, n);
  dead[c] = true;
  for (auto v: tree[c]) {
    if (dead[v]) continue;
    centroidTree[c].push_back(centroidDecomp(v));
  }
  return c;
}

void usage() {
  cin >> N;
  for (int i = 0; i < N-1; i++) {
    int u, v; cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  int centroid = centroidDecomp(1);
}
