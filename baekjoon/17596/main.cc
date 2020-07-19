#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
const int ST = 1<<17;
int N, V[MAXN], D[MAXN], Q;

struct Node {
  lld len;
  lld lmx[7], lmn[7], lpf[7];
  lld rmx[7], rmn[7], rpf[7];
  Node(): len(-1) {}
} seg[ST*2];

Node merge(Node a, Node b) {
  if (a.len == -1) return b;
  if (b.len == -1) return a;

  Node n;
  n.len = a.len + b.len;

  for (int d=0; d<7; d++) {
    int bd = (d+a.len) % 7;
    n.lmx[d] = max(a.lmx[d], b.lmx[bd]),
    n.lmn[d] = min(a.lmn[d], b.lmn[bd]),
    n.lpf[d] = max({a.lpf[d], b.lpf[bd], b.lmx[bd] - a.lmn[d]});

    int ad = (d+b.len) % 7;
    n.rmx[d] = max(b.rmx[d], a.rmx[ad]),
    n.rmn[d] = min(b.rmn[d], a.rmn[ad]),
    n.rpf[d] = max({b.rpf[d], a.rpf[ad], a.rmx[ad] - b.rmn[d]});
  }

  return n;
}

Node query(int n, int nl, int nr, int l, int r) {
  // cout << n << " " << nl << " " << nr << " " << l << " " << r << endl;
  if (l <= nl && nr <= r) return seg[n];
  if (nr < l || r < nl) return Node();
  int mid = (nl+nr+1)/2;
  return merge(query(n*2, nl, mid-1, l, r), query(n*2+1, mid, nr, l, r));
}

lld price(lld v, lld d, lld day) {
  if (day <= 3) return v + d*day;
  return v + d*(6-day);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> V[i] >> D[i];

  for (int i=0; i<N; i++) {
    for (int d=0; d<7; d++) {
      seg[ST+i].len = 1;
      seg[ST+i].lmn[d] = seg[ST+i].lmx[d] =
      seg[ST+i].rmn[d] = seg[ST+i].rmx[d] = price(V[i], D[i], d);
      seg[ST+i].lpf[d] = seg[ST+i].rpf[d] = 0;
    }
  }

  for (int i=ST-1; i>0; i--) seg[i] = merge(seg[i*2], seg[i*2+1]);

  cin >> Q;
  for (int i=0; i<Q; i++) {
    int s, t; cin >> s >> t;
    if (s < t) {
      Node n = query(1, 0, ST-1, s-1, t-1);
      cout << n.lpf[0] << endl;
    } else {
      Node n = query(1, 0, ST-1, t-1, s-1);
      cout << n.rpf[0] << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
