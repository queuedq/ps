#include "doll.h"
using namespace std;

const int MX = 1<<18;
int tree[MX*2], node[MX], state[MX*2];

void build(int u, int cnt, int &skip, int &id) {
  if (cnt <= skip) { // loop back to root
    skip -= cnt;
    tree[u] = -1;
    return;
  }
  if (cnt == 1) { // will point to trigger at leaf
    tree[u] = 0;
    return;
  }

  tree[u] = -(++id);
  node[id] = u;

  build(u*2, cnt/2, skip, id);
  build(u*2+1, cnt/2, skip, id);
}

int next_leaf() {
  int u = 1;
  while (tree[u] != 0) {
    state[u] ^= 1;
    u = u*2 + !state[u];
    if (tree[u] == -1) u = 1;
  }
  return u;
}

void create_circuit(int M, vector<int> A) {
  int N = A.size();

  int d = 1; // depth
  while (1<<d < N+1) d++;

  // build tree
  int skip = (1<<d) - (N+1);
  int S = 0;
  build(1, 1<<d, skip, S);

  // assign triggers
  for (int i=0; i<N; i++) tree[next_leaf()] = A[i];
  tree[next_leaf()] = 0;

  // answer
  vector<int> C(M+1, -1), X(S), Y(S); // C: all points to root
  for (int i=1; i<=S; i++) {
    int u = node[i];
    X[i-1] = tree[u*2];
    Y[i-1] = tree[u*2+1];
  }

  answer(C, X, Y);
}
