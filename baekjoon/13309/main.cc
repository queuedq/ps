#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 200005;
int N, Q;
int parent[MAX_N];
vector<int> adj[MAX_N], euler;
int firstPos[MAX_N], lastPos[MAX_N];

struct SegTree {
  static const int ST_SIZE = 1 << 20;
  static const int start = ST_SIZE / 2;
  pii depth[ST_SIZE];
  int cuts[ST_SIZE];

  SegTree() {
    fill(depth, depth + ST_SIZE, (pii){INT_MAX, -1});
  }

  void setDepth(int i, int node, int d) {
    depth[i + start] = {d, node};
  }

  void construct() {
    for (int i = start - 1; i > 0; i--) {
      depth[i] = min(depth[i*2], depth[i*2+1]);
    }
  }

  void updateCut(int i, int value) {
    int node = i + start;
    cuts[node] = value;
    node /= 2;
    while (node > 0) {
      cuts[node] = cuts[node*2] + cuts[node*2+1];
      node /= 2;
    }
  }

  pii queryDepth(int node, int nl, int nr, int l, int r) {
    if (nr <= l || r <= nl) { return {INT_MAX, -1}; }
    if (l <= nl && nr <= r) { return depth[node]; }
    int mid = (nl + nr) / 2;
    return min(queryDepth(node*2, nl, mid, l, r), queryDepth(node*2+1, mid, nr, l, r));
  }

  int queryCuts(int node, int nl, int nr, int l, int r) {
    if (nr <= l || r <= nl) { return 0; }
    if (l <= nl && nr <= r) { return cuts[node]; }
    int mid = (nl + nr) / 2;
    return queryCuts(node*2, nl, mid, l, r) + queryCuts(node*2+1, mid, nr, l, r);
  }
} seg;

////////////////////////////////

void input() {
  cin >> N >> Q;
  for (int i = 2; i <= N; i++) {
    cin >> parent[i];
    adj[parent[i]].push_back(i);
  }
}

void dfs(int c, int d) {
  firstPos[c] = euler.size();

  seg.setDepth(euler.size(), c, d);
  euler.push_back(c);
  for (int node: adj[c]) {
    dfs(node, d + 1);

    seg.setDepth(euler.size(), c, d);
    euler.push_back(c);
  }

  lastPos[c] = euler.size() - 1;
}

int lca(int u, int v) {
  int l = firstPos[u], r = firstPos[v];
  if (l > r) { swap(l, r); }
  return seg.queryDepth(1, 0, seg.start, l, r + 1).second;
}

void cut(int node) {
  // cout << "Cutting " << node << endl;
  seg.updateCut(firstPos[node], 1);
  seg.updateCut(lastPos[node] + 1, -1);
}

int countCuts(int u, int v) {
  int anc = lca(u, v);
  int uu = firstPos[u] + 1, vv = firstPos[v] + 1, aa = firstPos[anc] + 1;
  return seg.queryCuts(1, 0, seg.start, aa, uu) + seg.queryCuts(1, 0, seg.start, aa, vv);
}

string processQuery() {
  int b, c, d;
  cin >> b >> c >> d;
  string result;

  if (countCuts(b, c) == 0) {
    result = "YES";
    if (d == 1) { cut(b); }
  } else {
    result = "NO";
    if (d == 1) { cut(c); }
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  dfs(1, 0);
  seg.construct();
  for (int i = 0; i < Q; i++) {
    cout << processQuery() << endl;
  }

  // for (int i = seg.start; i < seg.start + 2*N; i++) {
  //   cout << euler[i - seg.start] << " ";
  //   cout << seg.cuts[i] << endl;
  // }

  ////////////////////////////////
  return 0;
}
