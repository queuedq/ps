#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct bipartite_matching {
  vector<vector<int>> adj; // Node indices are 1-based
  vector<int> S, T;
  vector<bool> vst;
  int cnt = 0;

  bipartite_matching(int N, int M, vector<vector<int>> &adj): adj(adj) {
    S.resize(N+1);
    T.resize(M+1);
    vst.resize(N+1);
  }

  void match() {
    int N = S.size()-1;
    for (int i=1; i<=N; i++) {
      fill(vst.begin(), vst.end(), false);
      cnt += match_node(i);
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

////////////////////////////////////////////////////////////////

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N+1);
    for (int i=0; i<M; i++) {
      int a, b; cin >> a >> b;
      adj[a+1].push_back(b+1);
    }

    bipartite_matching B(N, N, adj);
    B.match();

    cout << B.cnt << endl;
  }

  ////////////////////////////////
  return 0;
}
