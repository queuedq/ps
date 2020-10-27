#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

// Range min query
struct segtree {
  vector<lld> seg;
  int size;

  segtree(int sz) {
    size = 1 << (int)ceil(log2(sz));
    seg = vector<lld>(size*2, LLONG_MAX);
  }

  void update(int i, lld val) {
    seg[size+i] = val;
    for (int n = (size+i)/2; n > 0; n /= 2) {
      seg[n] = min(seg[n*2], seg[n*2+1]);
    }
  }

  // query [l, r]
  lld query(int l, int r) { return query(1, 0, size-1, l, r); }
  lld query(int n, int nl, int nr, int l, int r) {
    if (nr < l || r < nl) return LLONG_MAX;
    if (l <= nl && nr <= r) return seg[n];
    int mid = (nl+nr)/2;
    return min(query(n*2, nl, mid, l, r), query(n*2+1, mid+1, nr, l, r));
  }
};

////////////////////////////////////////////////////////////////
const int MAXN = 250'005;
int N, K;
lld A[MAXN], ord[MAXN], idx[MAXN];
vector<lld> S;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  S.resize(N+1);
  segtree rmin(N+1);

  for (int i=1; i<=N; i++) {
    cin >> A[i];
    S[i] = S[i-1] + A[i];
    ord[i] = i;
    idx[i] = -1;
  }

  sort(ord, ord+N+1, [&](int i, int j) { return S[i] < S[j]; });
  for (int i=0; i<=N; i++) rmin.update(i, ord[i]);

  priority_queue<pll> pq;
  for (int i=1; i<=N; i++) {
    int l=idx[i], r=N;
    while (l+1 < r) {
      int mid = (l+r)/2;
      if (rmin.query(idx[i]+1, mid) < i) r = mid;
      else l = mid;
    }
    idx[i] = r;
    pq.push({S[i] - S[ord[idx[i]]], i});
  }

  for (int k=0; k<K; k++) {
    assert(pq.size() > 0);
    auto [ans, i] = pq.top(); pq.pop();
    cout << ans << " ";

    int l=idx[i], r=N+1;
    while (l+1 < r) {
      int mid = (l+r)/2;
      if (rmin.query(idx[i]+1, mid) < i) r = mid;
      else l = mid;
    }
    idx[i] = r;

    if (idx[i] > N) continue;
    pq.push({S[i] - S[ord[idx[i]]], i});
  }

  ////////////////////////////////
  return 0;
}
