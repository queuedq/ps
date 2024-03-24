#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303;
int N, R[MN][MN], vst[MN];
vector<int> comp[MN];

void solve() {
  cin >> N;
  for (int u=0; u<N; u++) {
    string S; cin >> S;
    for (int v=0; v<N; v++) R[u][v] = S[v] - '0';
  }
      
  // find scc
  fill(vst, vst+N, 0);
  for (int u=0; u<N; u++) comp[u].clear();

  for (int u=0; u<N; u++) if (!vst[u]) {
    comp[u].push_back(u);
    for (int v=u+1; v<N; v++) {
      if (R[u][v] && R[v][u]) {
        vst[v] = 1;
        comp[u].push_back(v);
      }
    }
  }

  // transitive reduction
  for (int x=0; x<N; x++) if (!vst[x]) {
    for (int u=0; u<N; u++) if (!vst[u]) {
      for (int v=0; v<N; v++) if (!vst[v]) {
        if (u == x || x == v) continue;
        if (R[u][x] && R[x][v]) R[u][v] = 0;
      }
    }
  }

  // build graph
  vector<pii> ans;
  for (int u=0; u<N; u++) if (!vst[u]) {
    // dag
    for (int v=0; v<N; v++) if (!vst[v]) {
      if (u == v) continue;
      if (R[u][v]) ans.push_back({u, v});
    }

    // scc cycles
    int C = sz(comp[u]);
    if (C > 1) {
      for (int i=0; i<C; i++) ans.push_back({comp[u][i], comp[u][(i+1)%C]});
    }
  }

  cout << sz(ans) << endl;
  for (auto [u, v]: ans) cout << u+1 << " " << v+1 << endl;
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
