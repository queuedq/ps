#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<17;
const int INF = 1e9;
int N, L, K, H[ST], ans;

struct LazySeg {
  int seg[ST*2], lazy[ST*2];

  LazySeg() {
    fill(seg, seg+ST*2, INF);
    fill(lazy, lazy+ST*2, 0);
  }

  void push(int n, int nl, int nr) {
    seg[n*2] += lazy[n]; // min query
    seg[n*2+1] += lazy[n];
    lazy[n*2] += lazy[n];
    lazy[n*2+1] += lazy[n];
    lazy[n] = 0;
  }

  void add_range(int n, int nl, int nr, int l, int r, int v) {
    if (nr < l || r < nl) return;
    if (l <= nl && nr <= r) {
      seg[n] += v; // min query
      lazy[n] += v;
      return;
    }
    push(n, nl, nr);
    int m = (nl+nr)/2;
    add_range(n*2, nl, m, l, r, v);
    add_range(n*2+1, m+1, nr, l, r, v);
    seg[n] = min(seg[n*2], seg[n*2+1]); // min query
  }
  void add_range(int l, int r, int v) { add_range(1, 0, ST-1, l, r, v); }

  void set_min(int n, int nl, int nr, int i, int v) {
    if (n >= ST) { seg[n] = min(seg[n], v); return; }
    push(n, nl, nr);
    int m = (nl+nr)/2;
    if (i <= m) set_min(n*2, nl, m, i, v);
    else set_min(n*2+1, m+1, nr, i, v);
    seg[n] = min(seg[n*2], seg[n*2+1]);
  }
  void set_min(int i, int v) { set_min(1, 0, ST-1, i, v); }

  int query_min(int n, int nl, int nr, int l, int r) {
    if (nr < l || r < nl) return INF;
    if (l <= nl && nr <= r) return seg[n];
    push(n, nl, nr);
    int m = (nl+nr)/2;
    return min(query_min(n*2, nl, m, l, r), query_min(n*2+1, m+1, nr, l, r)); // min query
  }
  int query_min(int l, int r) { return query_min(1, 0, ST-1, l, r); }
} seg[11];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> L >> K;
  vector<int> hs;
  for (int i=1; i<=N; i++) { cin >> H[i]; hs.push_back(H[i]); }
  sort(all(hs));
  for (int i=1; i<=N; i++) H[i] = lower_bound(all(hs), H[i]) - hs.begin();

  // left: erase >= H[L]
  for (int i=1; i<L; i++) if (H[i] >= H[L]) ans++;

  // right: dp
  // D[i][k][h]: among buildings [L, i], make k visible, with max height h
  // if h < H[i]: D[i][k][h] = D[i-1][k][h] + 1  (remove H[i])
  // if h = H[i]: D[i][k][h] = min(D[i-1][k][h], D[i-1][k-1][0..h-1])  (use H[i])
  // if h > H[i]: D[i][k][h] = D[i-1][k][h]      (H[i] is invisible)
  seg[1].set_min(H[L], 0);
  for (int i=L+1; i<=N; i++) {
    // make seg[k][h] = D[i][k][h]
    for (int k=K; k>=1; k--) { // D[i][k] depends on D[i-1][k-1] -> reversed order
      seg[k].add_range(0, H[i]-1, 1); // remove H[i]
      int cost = seg[k-1].query_min(0, H[i]-1); // use H[i]
      seg[k].set_min(H[i], cost);
    }
  }

  ans += seg[K].query_min(0, ST-1);
  if (ans >= INF) cout << -1 << endl;
  else cout << ans << endl;

  ////////////////////////////////
  return 0;
}
