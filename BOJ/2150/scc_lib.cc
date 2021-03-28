#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

// 1-based index
struct scc {
  int N;
  vector<vector<int>> adj;
  stack<int> st;
  vector<int> scc_id, vst; // scc_id: Nodes' SCC component id
  int scc_cnt, vst_cnt;

  scc(const vector<vector<int>> &adj): N(adj.size()-1), adj(adj) {
    tarjan();
  }

  int dfs(int u) {
    int ret = vst[u] = ++vst_cnt;
    st.push(u);

    for (int v: adj[u]) {
      if (!vst[v]) ret = min(ret, dfs(v));
      else if (!scc_id[v]) ret = min(ret, vst[v]);
    }

    if (ret == vst[u]) {
      scc_cnt++;
      while (true) {
        int t = st.top(); st.pop();
        scc_id[t] = scc_cnt;
        if (t == u) break;
      }
    }

    return ret;
  }

  void tarjan() {
    st = stack<int>();
    scc_id = vst = vector<int>(N+1);
    scc_cnt = vst_cnt = 0;
    for (int i=1; i<=N; i++) {
      if (!vst[i]) dfs(i);
    }
  }

  // 0-based index
  vector<vector<int>> get_components() {
    vector<vector<int>> comp(scc_cnt);
    for (int i=1; i<=N; i++) comp[scc_id[i]-1].push_back(i);
    return comp;
  }
};

////////////////////////////////////////////////////////////////
int V, E;
vector<vector<int>> adj;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> V >> E;
  adj.resize(V + 1);
  for (int i = 0; i < E; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
  }

  scc S(adj);
  auto comp = S.get_components();

  vector<int> first;
  for (auto c: comp) first.push_back(c[0]);
  sort(first.begin(), first.end());

  cout << comp.size() << endl;
  for (auto f: first) {
    for (auto u: comp[S.scc_id[f]-1]) cout << u << " ";
    cout << -1 << endl;
  }

  ////////////////////////////////
  return 0;
}
