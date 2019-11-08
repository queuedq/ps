#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 200005;
const int ST_SIZE = 1 << 19;
const int MOD = 1000 * 1000 * 1000 + 7;

int N, M, C;
vector<int> adj[MAX_N];
int visited[MAX_N], subCnt[MAX_N];
vector<int> color, euler, invEuler;

pii Q[MAX_N];

struct SegTree{
  int start = ST_SIZE / 2;
  vector<int> seg[ST_SIZE];

  void construct() {
    for (int i = 0; i < N; i++) {
      seg[start + i].push_back(color[euler[i]]);
    }
    for (int i = start - 1; i > 0; i--) {
      merge(
        seg[i*2].begin(), seg[i*2].end(),
        seg[i*2+1].begin(), seg[i*2+1].end(),
        back_inserter(seg[i])
      );
    }
  }

  int query_(int node, int nodeL, int nodeR, int l, int r, int c) {
    if (r <= nodeL || nodeR <= l) { return 0; }
    if (l <= nodeL && nodeR <= r) {
      return upper_bound(seg[node].begin(), seg[node].end(), c) - seg[node].begin();
    }
    int mid = (nodeL + nodeR) / 2;
    return query_(node*2, nodeL, mid, l, r, c) + query_(node*2+1, mid, nodeR, l, r, c);
  }

  int query(int v, int c) {
    // cout << invEuler[v] << " " << invEuler[v] + subCnt[v] << endl;
    return query_(1, 0, start, invEuler[v], invEuler[v] + subCnt[v], c);
  }
};

void input() {
  cin >> N >> M >> C;
  color.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> color[i];
  }
  for (int i = 0; i < N - 1; i++) {
    int a, b; cin >> a >> b; a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 0; i < M; i++) {
    int v, c; cin >> v >> c; v--;
    Q[i] = {v, c};
  }
}

int dfs(int c) {
  visited[c] = true;
  euler.push_back(c);
  int cnt = 1;
  for (int node: adj[c]) {
    if (visited[node]) { continue; }
    cnt += dfs(node);
  }
  return subCnt[c] = cnt;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  dfs(0);

  invEuler.resize(N);
  for (int i = 0; i < N; i++) { invEuler[euler[i]] = i; }

  SegTree *seg = new SegTree();
  seg->construct();

  lld result = 0;
  for (int i = 0; i < M; i++) {
    // cout << seg->query(Q[i].first, Q[i].second) << endl;
    result += seg->query(Q[i].first, Q[i].second);
    result %= MOD;
  }
  cout << result << endl;

  ////////////////////////////////
  return 0;
}
