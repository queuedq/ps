#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct merge_tree {
  vector<vector<pll>> seg;
  int size;

  merge_tree(const vector<lld> &A) {
    size = 1 << (int)ceil(log2(A.size()));
    seg = vector<vector<pll>>(size*2);
    for (int i=0; i<A.size(); i++) seg[size+i].push_back({A[i], i});
    for (int n=size-1; n>0; n--) {
      merge(
        seg[n*2].begin(), seg[n*2].end(),
        seg[n*2+1].begin(), seg[n*2+1].end(),
        back_inserter(seg[n])
      );
    }
  }

  pll query(int l, int r, pll v) { return query(1, 0, size-1, l, r, v); }
  pll query(int n, int nl, int nr, int l, int r, pll v) {
    if (nr < l || r < nl) return {LLONG_MAX, -1};
    if (l <= nl && nr <= r) {
      auto it = upper_bound(seg[n].begin(), seg[n].end(), v);
      if (it == seg[n].end()) return {LLONG_MAX, -1};
      return *it;
    }
    int mid = (nl+nr)/2;
    return min(
      query(n*2, nl, mid, l, r, v),
      query(n*2+1, mid+1, nr, l, r, v)
    );
  }
};

////////////////////////////////////////////////////////////////
const int MAXN = 250'005;
int N, K;
lld A[MAXN], idx[MAXN];
vector<lld> S;
priority_queue<pll> pq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  S.resize(N+1);
  for (int i=1; i<=N; i++) cin >> A[i];

  lld smin = 0, sidx = 0;
  for (int i=1; i<=N; i++) {
    S[i] = S[i-1] + A[i];
    pq.push({S[i] - smin, i});
    idx[i] = sidx;
    tie(smin, sidx) = min(pll(smin, sidx), pll(S[i], i));
  }

  merge_tree T(S);

  for (int k=0; k<K; k++) {
    assert(pq.size() > 0);
    auto [ans, i] = pq.top(); pq.pop();
    cout << ans << " ";

    auto nxt = T.query(0, i-1, {S[idx[i]], idx[i]});
    if (nxt.second == -1) continue;
    pq.push({S[i] - nxt.first, i});
    idx[i] = nxt.second;
  }

  ////////////////////////////////
  return 0;
}
