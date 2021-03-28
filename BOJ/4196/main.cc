#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
int N, M;
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
  cin >> N >> M;
  adj = vector<vector<int>>(N + 1);
  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
  }
}

void solve() {
  tarjan();

  vector<int> indeg; indeg.resize(sccCnt);

  for (int i = 1; i < adj.size(); i++) {
    for (int node: adj[i]) {
      if (sccId[i] != sccId[node]) indeg[sccId[node]]++;
    }
  }

  int ans = 0;
  for (int i = 0; i < indeg.size(); i++) {
    if (indeg[i] == 0) ans++;
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    input();
    solve();
  }

  ////////////////////////////////
  return 0;
}
