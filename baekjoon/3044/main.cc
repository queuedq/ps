#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9;

int N, M;
vector<pll> D;

class SCC {
public:
  vector<vector<int>> adj, sccAdj;
  vector<int> sccId, dfsn, sccSize;
  stack<int> st;
  int cnt, vCnt;

  int scc(int here) {
    int ret = dfsn[here] = ++vCnt;
    st.push(here);

    for (int node: adj[here]) {
      if (dfsn[node] == -1) ret = min(ret, scc(node));
      else if (sccId[node] == -1) ret = min(ret, dfsn[node]);
    }

    if (ret == dfsn[here]) {
      cnt++;
      while (true) {
        int t = st.top(); st.pop();
        sccId[t] = cnt;
        if (t == here) break;
      }
    }

    return ret;
  }

  vector<int> tarjan() {
    st = stack<int>();
    sccId = dfsn = vector<int>(adj.size(), -1);
    cnt = vCnt = 0;
    for (int i = 1; i < adj.size(); i++) {
      if (dfsn[i] == -1) scc(i);
    }
    return sccId;
  }

  void getComp() {
    sccSize.resize(cnt + 1); sccAdj.resize(cnt + 1);

    for (int i = 1; i < adj.size(); i++) {
      sccSize[sccId[i]]++;
      for (int node: adj[i]) {
        if (sccId[i] != sccId[node]) {
          sccAdj[sccId[i]].push_back(sccId[node]);
        }
      }
    }
  }
} scc;

void input() {
  cin >> N >> M;
  scc.adj = vector<vector<int>>(N + 1);
  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    scc.adj[a].push_back(b);
  }
}

// {-1, -1}: not visited
// {0, x}: x ways
// {1, x}: k * MOD + x ways, where k >= 1
// {2, 0}: infinite ways
pll dp(int here) {
  if (D[here] != pll(-1, -1)) { return D[here]; }
  if (here == scc.sccId[2]) {
    if (scc.sccSize[here] > 1) return D[here] = {2, 0};
    else return D[here] = {0, 1};
  }

  lld overflow = 0, ret = 0;
  for (int comp: scc.sccAdj[here]) {
    lld compOver, num;
    tie(compOver, num) = dp(comp);
    if (compOver == 2) return D[here] = {2, 0};
    if ((compOver == 1 || num > 0) && scc.sccSize[comp] > 1) {
      return D[here] = {2, 0};
    }

    ret = ret + num;
    if (compOver == 1 || ret >= MOD) {
      ret %= MOD;
      overflow = 1;
    }
  }

  return D[here] = {overflow, ret};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  scc.tarjan();
  scc.getComp();

  D = vector<pll>(scc.cnt + 1, {-1, -1});
  pll ans = dp(scc.sccId[1]);
  if (ans.first == 2) {
    cout << "inf" << endl;
  } else if (ans.first == 1) {
    cout << setfill('0') << setw(9) << ans.second << endl;
  } else {
    cout << ans.second << endl;
  }

  ////////////////////////////////
  return 0;
}
