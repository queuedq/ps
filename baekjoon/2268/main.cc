#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 1'000'005;
int N, M;

struct SegTree {
  static const int ST_SIZE = 1 << 21;
  static const int start = ST_SIZE / 2;
  lld arr[ST_SIZE];

  void update(int pos, int value) {
    int node = start + pos;
    arr[node] = value;
    while (node > 1) {
      node /= 2;
      arr[node] = arr[node*2] + arr[node*2+1];
    }
  }

  lld query(int l, int r) { return query(1, 0, start, l, r); }
  lld query(int node, int nl, int nr, int l, int r) {
    if (nr <= l || r <= nl) return 0;
    if (l <= nl && nr <= r) return arr[node];
    int mid = (nl + nr) / 2;
    return query(node*2, nl, mid, l, r) + query(node*2+1, mid, nr, l, r);
  }
} seg;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int q, a, b; cin >> q >> a >> b;
    if (q == 0) {
      if (a > b) swap(a, b);
      cout << seg.query(a - 1, b) << endl;
    } else {
      seg.update(a - 1, b);
    }
  }

  ////////////////////////////////
  return 0;
}
