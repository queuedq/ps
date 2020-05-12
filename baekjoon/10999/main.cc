#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<20;
int N, M, K;
lld seg[ST * 2];
lld add[ST * 2];

void propagate(int n, int nl, int nr) {
  seg[n] += add[n] * (nr-nl+1);
  if (n < ST) {
    add[n*2] += add[n];
    add[n*2+1] += add[n];
  }
  add[n] = 0;
}

void update(int n, int nl, int nr, int l, int r, lld v) {
  propagate(n, nl, nr);
  if (nr < l || r < nl) return;
  if (l <= nl && nr <= r) { add[n] += v; return propagate(n, nl, nr); }

  int mid = (nl+nr+1)/2;
  update(n*2, nl, mid-1, l, r, v);
  update(n*2+1, mid, nr, l, r, v);
  seg[n] = seg[n*2] + seg[n*2+1];
}

lld query(int n, int nl, int nr, int l, int r) {
  propagate(n, nl, nr);
  if (nr < l || r < nl) return 0;
  if (l <= nl && nr <= r) return seg[n];

  int mid = (nl+nr+1)/2;
  return query(n*2, nl, mid-1, l, r) + query(n*2+1, mid, nr, l, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=1; i<=N; i++) {
    cin >> seg[i+ST];
  }

  // Construct
  for (int i=ST-1; i>0; i--) {
    seg[i] = seg[i*2] + seg[i*2+1];
  }

  for (int q=0; q<M+K; q++) {
    lld a, b, c, d; cin >> a;
    if (a == 1) {
      cin >> b >> c >> d;
      update(1, 0, ST-1, b, c, d);
    } else {
      cin >> b >> c;
      cout << query(1, 0, ST-1, b, c) << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
