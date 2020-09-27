#include "template.h"

struct bipartite_matching {
  vector<vector<int>> adj; // Node indices are 1-based
  vector<int> S, T;
  vector<bool> vst;

  bipartite_matching(int N, int M, vector<vector<int>> &adj): adj(adj) {
    S.resize(N+1);
    T.resize(M+1);
    vst.resize(N+1);
  }

  void match() {
    int N = S.size()-1;
    for (int i=1; i<=N; i++) {
      fill(vst.begin(), vst.end(), false);
      match_node(i);
    }
  }

  bool match_node(int u) {
    if (vst[u]) return false;
    vst[u] = true;

    for (int v: adj[u]) {
      if (!T[v] || match_node(T[v])) {
        S[u] = v;
        T[v] = u;
        return true;
      }
    }
    return false;
  }
};

int main() {
  vector<vector<int>> adj(6);
  adj[1] = {2, 3};
  adj[2] = {3};
  adj[3] = {1, 4};
  adj[4] = {3};
  adj[5] = {4};

  bipartite_matching B(5, 5, adj);
  B.match();

  for (int i=1; i<=5; i++) {
    cout << i << " -> " << B.S[i] << endl;
  }

  return 0;
}
