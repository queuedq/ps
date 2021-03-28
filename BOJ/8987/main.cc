#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 3e5+5;

// Range min + index query
struct segtree {
  vector<pll> seg;
  int size;

  segtree(int sz) {
    size = 1 << (int)ceil(log2(sz));
    seg = vector<pll>(size*2, {LLONG_MAX, -1});
  }

  void update(int i, lld val) {
    seg[size+i] = {val, i};
    for (int n = (size+i)/2; n > 0; n /= 2) {
      seg[n] = min(seg[n*2], seg[n*2+1]);
    }
  }

  // query [l, r]
  pll query(int l, int r) { return query(1, 0, size-1, l, r); }
  pll query(int n, int nl, int nr, int l, int r) {
    if (nr < l || r < nl) return {LLONG_MAX, -1};
    if (l <= nl && nr <= r) return seg[n];
    int mid = (nl+nr)/2;
    return min(query(n*2, nl, mid, l, r), query(n*2+1, mid+1, nr, l, r));
  }
} rmq(MAXN);


lld N, K, W[MAXN];
struct Rect { lld l, r, h; } A[MAXN];
vector<int> adj[MAXN];
pll D[MAXN]; // max cost path (max cost, next node)

int makeTree(int l, int r, lld h) {
  if (l > r) return -1;
  auto [mh, t] = rmq.query(l, r);
  int tl = makeTree(l, t-1, mh);
  int tr = makeTree(t+1, r, mh);
  if (tl != -1) adj[t].push_back(tl);
  if (tr != -1) adj[t].push_back(tr);
  W[t] = (A[r].r - A[l].l) * (mh - h);
  return t;
}

lld dfs(int u) {
  D[u] = {0, -1};
  for (auto v: adj[u]) D[u] = max(D[u], {dfs(v), v});
  D[u].first += W[u];
  return D[u].first;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  N = N/2-1;
  lld x, y; cin >> x >> y;
  for (int i=0; i<N; i++) {
    cin >> x >> y;
    A[i].l = x; A[i].h = y;
    cin >> x >> y;
    A[i].r = x;

    rmq.update(i, y);
  }
  cin >> x >> y;
  cin >> K;

  int root = makeTree(0, N-1, 0);
  dfs(root);

  priority_queue<pll> pq;
  pq.push({D[root].first, root});

  lld ans = 0;
  while (!pq.empty() && K > 0) {
    auto [d, u] = pq.top(); pq.pop();
    ans += d;

    while (u != -1) {
      for (auto v: adj[u]) {
        if (v == D[u].second) continue;
        pq.push({D[v].first, v});
      }
      u = D[u].second;
    }

    K--;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
