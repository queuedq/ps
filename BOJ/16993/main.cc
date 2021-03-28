#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
const int ST = 1<<17;
const int INF = 1e9+5;
int N, M, A[MAXN];

struct Node {
  int l, r, m, s;
  Node() { l = r = m = -INF; s = 0; }
  Node(int l, int r, int m, int s): l(l), r(r), m(m), s(s) {}
} seg[ST*2];

Node merge(Node x, Node y) {
  return {
    max(x.l, x.s+y.l),
    max(y.r, y.s+x.r),
    max({x.m, y.m, x.r+y.l}),
    x.s+y.s
  };
}

Node query(int n, int nl, int nr, int l, int r) {
  if (nr < l || r < nl) return Node();
  if (l <= nl && nr <= r) return seg[n];
  int mid = (nl+nr+1)/2;
  return merge(query(n*2, nl, mid-1, l, r), query(n*2+1, mid, nr, l, r));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];

  // Contruct segtree
  for (int i=1; i<=N; i++) seg[ST+i] = {A[i], A[i], A[i], A[i]};
  for (int i=ST-1; i>0; i--) seg[i] = merge(seg[i*2], seg[i*2+1]);

  // Query
  cin >> M;
  for (int i=0; i<M; i++) {
    int l, r; cin >> l >> r;
    cout << query(1, 0, ST-1, l, r).m << endl;
  }

  ////////////////////////////////
  return 0;
}
