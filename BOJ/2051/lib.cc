#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
// 1-based index
const int MN = 1005;
int L, R;
vector<int> adj[MN];

struct bipartite_matching {
  int cnt, S[MN], T[MN], vst[MN], rvst[MN];
  vector<int> lc, rc;

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
    fill(S+1, S+L+1, 0);
    fill(T+1, T+R+1, 0); // R
    cnt = 0;

    // find matching
    for (int u=1; u<=L; u++) {
      fill(vst+1, vst+L+1, 0);
      cnt += match_node(u);
    }
    return cnt;
  }

  // min vertex cover
  void dfs(int u) {
    if (vst[u]) return;
    vst[u] = 1;

    for (int v: adj[u]) {
      rvst[v] = 1;
      if (T[v]) dfs(T[v]);
    }
  }
  
  void vertex_cover() {
    // reset
    fill(vst+1, vst+L+1, 0);
    fill(rvst+1, rvst+R+1, 0); // R

    // find vertex cover
    for (int u=1; u<=L; u++) { if (!S[u]) dfs(u); }
    for (int u=1; u<=L; u++) { if (!vst[u]) lc.push_back(u); }
    for (int v=1; v<=R; v++) { if (rvst[v]) rc.push_back(v); } // R
  }
};

bipartite_matching BM;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> L >> R;
  for (int u=1; u<=L; u++) {
    int k; cin >> k;
    for (int j=0; j<k; j++) {
      int v; cin >> v;
      adj[u].push_back(v);
    }
  }

  BM.match();
  BM.vertex_cover();

  cout << BM.cnt << endl;

  cout << BM.lc.size() << " ";
  for (auto u: BM.lc) cout << u << " ";
  cout << endl;

  cout << BM.rc.size() << " ";
  for (auto v: BM.rc) cout << v << " ";
  cout << endl;

  ////////////////////////////////
  return 0;
}
