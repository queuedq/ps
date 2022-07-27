#include "game.h"

int cnt[1500];

void initialize(int n) { }

int hasEdge(int u, int v) {
  if (u < v) u = v;
  cnt[u]++;
  return cnt[u] == u;
}
