#include "towns.h"
#include "bits/stdc++.h"
using namespace std;

const int MN = 2020;
int G[MN][MN], deg[MN];

int get_dir(int u, int v) {
  if (G[u][v] || G[v][u]) return G[u][v];
  bool b = check_road(u, v);
  if (!b) swap(u, v);
  G[u][v] = 1;
  deg[u]++;
  return b;
}

int find_town(int N) {
  // make all nodes outdeg = 1 except root
  int root = 0;
  for (int i=1; i<N; i++) {
    if (get_dir(root, i)) root = i;
  }

  // check if root outdeg >= 2
  for (int i=0; i<N; i++) {
    if (i == root) continue;
    get_dir(root, i);
    if (deg[root] >= 2) break;
  }
  if (deg[root] <= 1) return root;

  // make all nodes outdeg = 2 except at most two nodes
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (i == j || deg[i] >= 2 || deg[j] >= 2) continue;
      get_dir(i, j);
    }
  }

  // check the remaining nodes with outdeg = 1
  for (int i=0; i<N; i++) {
    if (deg[i] >= 2) continue;
    for (int j=0; j<N; j++) {
      if (i == j) continue;
      get_dir(i, j);
      if (deg[i] >= 2) break;
    }
    if (deg[i] <= 1) return i;
  }

  return -1;
}
