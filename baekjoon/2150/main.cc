#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
int V, E;
vector<vector<int>> adj;
vector<int> sccId, discovered;
stack<int> st;
int sccCnt, vertexCnt;

int scc(int here) {
  int ret = discovered[here] = vertexCnt++;
  st.push(here);

  for (int node: adj[here]) {
    if (discovered[node] == -1) ret = min(ret, scc(node));
    else if (sccId[node] == -1) ret = min(ret, discovered[node]);
  }

  if (ret == discovered[here]) {
    while (true) {
      int t = st.top(); st.pop();
      sccId[t] = sccCnt;
      if (t == here) break;
    }
    sccCnt++;
  }

  return ret;
}

vector<int> tarjan() {
  sccId = discovered = vector<int>(adj.size(), -1);
  st = stack<int>();
  sccCnt = vertexCnt = 0;
  for (int i = 1; i < adj.size(); i++) {
    if (discovered[i] == -1) scc(i);
  }
  return sccId;
}

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
  tarjan();

  vector<vector<int>> sccGroups;
  sccGroups.resize(sccCnt + 1);
  vector<int> order;

  for (int i = 1; i <= V; i++) {
    if (sccGroups[sccId[i]].empty()) order.push_back(sccId[i]);
    sccGroups[sccId[i]].push_back(i);
  }

  cout << sccCnt << endl;
  for (int i = 0; i < sccCnt; i++) {
    for (int node: sccGroups[order[i]]) {
      cout << node << " ";
    }
    cout << -1 << endl;
  }

  ////////////////////////////////
  return 0;
}
