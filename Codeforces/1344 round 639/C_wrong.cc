#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 2e5+5;
int N, M;
vector<int> adj[MAXN];
vector<int> inv[MAXN];
bool vst[MAXN];
bool mark[MAXN];
bool ok = true;
vector<char> ans;

void dfs1(int u) {
  if (mark[u]) { ok = false; return; } // Cycle
  if (vst[u]) return;
  mark[u] = true;
  vst[u] = true;
  for (auto v: adj[u]) {
    dfs1(v);
  }
  mark[u] = false;
}

void dfs2(int u) {
  if (mark[u]) { ok = false; return; } // Cycle
  if (vst[u]) return;
  mark[u] = true;
  vst[u] = true;
  for (auto v: inv[u]) {
    dfs2(v);
  }
  mark[u] = false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    inv[b].push_back(a);
  }

  int cnt = 0;
  for (int i=1; i<=N; i++) {
    if (!vst[i]) {
      ans.push_back('A');
      cnt++;
    } else {
      ans.push_back('E');
    }

    dfs1(i);
    vst[i] = false;
    dfs2(i);
    if (!ok) { cout << -1 << endl; return 0; }
  }

  cout << cnt << endl;
  for (auto a: ans) cout << a;
  cout << endl;

  ////////////////////////////////
  return 0;
}
