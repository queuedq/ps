#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
int N, M, S, P;
vector<vector<int>> adj;
vector<int> W, res;
vector<vector<int>> sccAdj;
vector<int> sccW, sccRes;
vector<lld> D;

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

////////////////

void input() {
  cin >> N >> M;

  adj.resize(N + 1);
  W.resize(N + 1);
  res.resize(N + 1);

  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
  }
  for (int i = 1; i <= N; i++) {
    cin >> W[i];
  }

  cin >> S >> P;
  for (int i = 0; i < P; i++) {
    int r; cin >> r;
    res[r] = 1;
  }
}

void getSccInfo(SCC &scc) {
  sccAdj.resize(scc.cnt + 1);
  sccW.resize(scc.cnt + 1);
  sccRes.resize(scc.cnt + 1);

  for (int i = 1; i <= N; i++) {
    int id = scc.id[i];
    sccW[id] += W[i];
    sccRes[id] += res[i];
    for (int node: adj[i]) {
      int nodeId = scc.id[node];
      if (id != nodeId) {
        sccAdj[nodeId].push_back(id); // reversed
      }
    }
  }
}

lld dp(int here, SCC &scc) {
  if (D[here] != -1) return D[here];
  if (here == scc.id[S]) return D[scc.id[S]] = sccW[scc.id[S]];

  lld ret = LLONG_MIN;
  for (int comp: sccAdj[here]) {
    ret = max(ret, dp(comp, scc));
  }
  if (ret != LLONG_MIN) {
    ret += sccW[here];
  }

  return D[here] = ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  SCC scc = SCC(adj);
  scc.tarjan();

  getSccInfo(scc);

  D = vector<lld>(scc.cnt + 1, -1);

  lld ans = 0;
  for (int id = 1; id <= scc.cnt; id++) {
    dp(id, scc);
    if (sccRes[id] > 0) ans = max(ans, D[id]);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
