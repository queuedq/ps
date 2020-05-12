#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
const int ST = 1<<17;
int N, M, seg[ST*2], ans[MAXN];
pii A[MAXN];

struct Query {
  int l, r, k, idx;

  bool operator <(const Query q) const { return k > q.k; }
} Q[MAXN];

void update(int i, int val) {
  int n = ST+i;
  seg[n] = val;
  while (n > 1) {
    n >>= 1;
    seg[n] = seg[n*2] + seg[n*2+1];
  }
}

int query(int n, int nl, int nr, int l, int r) {
  if (nr < l || r < nl) return 0;
  if (l <= nl && nr <= r) return seg[n];
  int mid = (nl+nr+1)/2;
  return query(n*2, nl, mid-1, l, r) + query(n*2+1, mid, nr, l, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int a; cin >> a;
    A[i] = {a, i+1};
  }

  cin >> M;
  for (int i=0; i<M; i++) {
    int l, r, k; cin >> l >> r >> k;
    Q[i] = {l, r, k, i};
  }

  sort(A, A+N, greater<pii>());
  sort(Q, Q+M); // 버그 수정 N -> M. 내 세시간...ㅠㅠ

  int j = 0;
  for (int i=0; i<M; i++) {
    while (j < N && A[j].first > Q[i].k) {
      update(A[j].second, 1);
      j++;
    }
    ans[Q[i].idx] = query(1, 0, ST-1, Q[i].l, Q[i].r);
  }

  for (int i=0; i<M; i++) {
    cout << ans[i] << endl;
  }

  ////////////////////////////////
  return 0;
}
