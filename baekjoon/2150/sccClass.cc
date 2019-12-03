#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
int V, E;
vector<vector<int>> adj;

class SCC {
public:
  const vector<vector<int>> &adj;
  stack<int> st;
  vector<int> id, dfsn;
  int cnt, vCnt;

  SCC(const vector<vector<int>> &adj): adj(adj) { }

  int scc(int here) {
    int ret = dfsn[here] = ++vCnt;
    st.push(here);

    for (int node: adj[here]) {
      if (dfsn[node] == -1) ret = min(ret, scc(node));
      else if (id[node] == -1) ret = min(ret, dfsn[node]);
    }

    if (ret == dfsn[here]) {
      cnt++;
      while (true) {
        int t = st.top(); st.pop();
        id[t] = cnt;
        if (t == here) break;
      }
    }

    return ret;
  }

  vector<int> tarjan() {
    st = stack<int>();
    id = dfsn = vector<int>(adj.size(), -1);
    cnt = vCnt = 0;
    for (int i = 1; i < adj.size(); i++) {
      if (dfsn[i] == -1) scc(i);
    }
    return id;
  }
};

void input() {
  cin >> V >> E;
  adj.resize(V + 1);
  for (int i = 0; i < E; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  SCC scc = SCC(adj);
  scc.tarjan();

  vector<vector<int>> sccGroups;
  sccGroups.resize(scc.cnt + 1);
  vector<int> order;

  for (int i = 1; i <= V; i++) {
    if (sccGroups[scc.id[i]].empty()) order.push_back(scc.id[i]);
    sccGroups[scc.id[i]].push_back(i);
  }

  cout << scc.cnt << endl;
  for (int i = 0; i < scc.cnt; i++) {
    for (int node: sccGroups[order[i]]) {
      cout << node << " ";
    }
    cout << -1 << endl;
  }

  ////////////////////////////////
  return 0;
}
