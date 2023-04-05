#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 105;
int N, vst[MN], cnt[26];
string S[MN];
vector<int> adj[MN], topo;

int par[MN];
vector<int> comp[MN];

void dfs(int u) {
  vst[u] = 1;
  for (auto v: adj[u]) {
    if (vst[v]) continue;
    dfs(v);
  }
  topo.push_back(u);
}

int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

void merge(int x, int y) {
  x = find(x); y = find(y);
  if (x == y) return;
  par[y] = x;
}

string solve() {
  cin >> N;
  // reset
  fill(vst, vst+N, 0);
  fill(cnt, cnt+26, 0);
  for (int i=0; i<N; i++) {
    adj[i].clear();
    comp[i].clear();
    par[i] = i;
  }
  topo.clear();

  for (int i=0; i<N; i++) cin >> S[i];
  
  // build graph
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (i == j) continue;
      if (S[i].back() == S[j].front()) {
        adj[i].push_back(j);
        merge(i, j);
      }
    }
  }

  // get components
  for (int i=0; i<N; i++) {
    comp[find(i)].push_back(i);
  }

  // toposort each component
  for (int i=0; i<N; i++) {
    for (auto j: comp[i]) {
      if (!vst[j]) dfs(j);
    }
  }
  reverse(all(topo));

  // answer
  string ans;
  bool ok = 1;
  char prv = '\0';
  for (auto i: topo) {
    for (auto c: S[i]) {
      ans.push_back(c);
      if (c != prv) cnt[c-'A']++;
      if (cnt[c-'A'] > 1) ok = 0;
      prv = c;
    }
  }

  if (!ok) return "IMPOSSIBLE";
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    string answer = solve();
    cout << "Case #" << t << ": " << answer << endl;
  }

  ////////////////////////////////
  return 0;
}
