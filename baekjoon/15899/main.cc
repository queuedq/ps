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
vector<int> color, invColor[MAX_N], euler, invEuler;

struct SegTree{
  int start = ST_SIZE / 2;
  int seg[ST_SIZE];

  void update(int v) {
    v = start + invEuler[v];
    while (v > 0) {
      seg[v]++;
      v /= 2;
    }
  }

  int query_(int node, int nodeL, int nodeR, int l, int r, int c) {
    if (r <= nodeL || nodeR <= l) { return 0; }
    if (l <= nodeL && nodeR <= r) { return seg[node]; }
    int mid = (nodeL + nodeR) / 2;
    return query_(node*2, nodeL, mid, l, r, c) + query_(node*2+1, mid, nodeR, l, r, c);
  }

  int query(int v, int c) {
    // cout << invEuler[v] << " " << invEuler[v] + subCnt[v] << endl;
    return query_(1, 0, start, invEuler[v], invEuler[v] + subCnt[v], c);
  }
};

struct Query {
  int v, c;
};

Query Q[MAX_N];

bool qcmp(Query a, Query b) {
  return (pii){a.c, a.v} < (pii){b.c, b.v};
}

void input() {
  cin >> N >> M >> C;
  color.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> color[i];
    invColor[color[i]].push_back(i);
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
  sort(Q, Q + M, qcmp);
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

  lld result = 0;
  int c = 1;
  for (int i = 0; i < M; i++) {
    while (c <= Q[i].c) {
      for (int j: invColor[c]) { seg->update(j); }
      c++;
    }
    result += seg->query(Q[i].v, Q[i].c);
    result %= MOD;
  }
  cout << result << endl;

  ////////////////////////////////
  return 0;
}
