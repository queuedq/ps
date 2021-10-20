#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 305;
int N, M, K, A[MN][MN];
vector<int> adj[MN];

struct bipartite_matching {
  int cnt, S[MN], T[MN], vst[MN], rvst[MN], lcnt, lc[MN], rc[MN];

  // max matching
  bool match_node(int u) {
    if (vst[u]) return 0;
    vst[u] = 1;

    for (int v: adj[u]) {
      if (!T[v] || match_node(T[v])) {
        S[u] = v; T[v] = u;
        return 1;
      }
    }
    return 0;
  }

  int match() {
    // reset
    fill(S+1, S+N+1, 0);
    fill(T+1, T+M+1, 0); // M
    cnt = 0;

    // find matching
    for (int u=1; u<=N; u++) {
      fill(vst+1, vst+N+1, 0);
      cnt += match_node(u);
    }
    return cnt;
  }

  // min vertex cover
  void dfs(int u) {
    if (vst[u]) return;
    vst[u] = 1; lcnt--;

    for (int v: adj[u]) {
      rvst[v] = 1;
      if (T[v]) dfs(T[v]);
    }
  }
  
  void vertex_cover() {
    // reset
    fill(vst+1, vst+N+1, 0);
    fill(rvst+1, rvst+M+1, 0); // M
    lcnt = N;

    // find vertex cover
    for (int u=1; u<=N; u++) { if (!S[u]) dfs(u); }
    for (int u=1; u<=N; u++) { lc[u] = !vst[u]; }
    for (int v=1; v<=M; v++) { rc[v] = rvst[v]; } // M
  }
} BM;

void make_graph(int x) {
  for (int i=1; i<=N; i++) {
    adj[i].clear();
    for (int j=1; j<=M; j++) {
      if (A[i][j] > x) adj[i].push_back(j);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) cin >> A[i][j];
  }

  int l = 0, r = 505050;
  while (l+1 < r) {
    int m = (l+r)/2;
    make_graph(m);
    if (BM.match() <= K) r = m;
    else l = m;
  }
  
  make_graph(r);
  BM.match();
  BM.vertex_cover();

  // output
  cout << r << endl;

  cout << BM.lcnt << " ";
  for (int u=1; u<=N; u++) { if (BM.lc[u]) cout << u << " "; } 
  cout << endl;

  cout << K - BM.lcnt << " ";
  for (int v=1; v<=M; v++) { if (BM.rc[v] || BM.cnt++ < K) cout << v << " "; }
  cout << endl;

  ////////////////////////////////
  return 0;
}
