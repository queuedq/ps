#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9;
const int ST = 1<<19;

int I[ST][2], seg[ST*2], lazy[ST*2];

void init(int N) {
  for (int i=0; i<ST; i++) seg[i+ST] = (i<=N) ? -i : -INF;
  for (int n=ST-1; n>0; n--) seg[n] = max(seg[n*2], seg[n*2+1]);
}

void push(int n) {
  lazy[n*2] += lazy[n];
  lazy[n*2+1] += lazy[n];
  seg[n*2] += lazy[n];
  seg[n*2+1] += lazy[n];
  lazy[n] = 0;
}

void add(int n, int nl, int nr, int l, int r, int v) {
  if (nr < l || r < nl) return;
  if (l <= nl && nr <= r) { seg[n] += v; lazy[n] += v; return; }
  int m = (nl+nr+1)/2;
  push(n);
  add(n*2, nl, m-1, l, r, v);
  add(n*2+1, m, nr, l, r, v);
  seg[n] = max(seg[n*2], seg[n*2+1]);
}

int get(int i) {
  int res = seg[i+=ST];
  for (i/=2; i>0; i/=2) res += lazy[i];
  return res;
}

int query(int n) { // max index of seg >= 0
  if (n >= ST) return n-ST;
  push(n);
  if (seg[n*2+1] >= 0) return query(n*2+1);
  else return query(n*2);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int N; cin >> N;
  init(N);
  for (int i=1; i<=N; i++) {
    cin >> I[i][0] >> I[i][1];
    add(1, 0, ST-1, I[i][0], I[i][1], 1);
  }

  cout << query(1) << " ";

  int Q; cin >> Q;
  while (Q--) {
    int p, l, r; cin >> p >> l >> r;
    add(1, 0, ST-1, I[p][0], I[p][1], -1);
    I[p][0] = l, I[p][1] = r;
    add(1, 0, ST-1, l, r, 1);

    cout << query(1) << " ";
  }

  ////////////////////////////////
  return 0;
}
