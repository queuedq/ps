#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
const int BKT = 400;
lld N, M, A[MN], B[MN], ans[MN], cntA[MN], cntB[MN];

struct Query {
  int l, r, k, i;
  bool operator <(const Query &Q) const {
    if (l/BKT == Q.l/BKT) return r < Q.r;
    return l/BKT < Q.l/BKT;
  }
} Q[MN];

struct Fenwick {
  int F[MN];

  void upd(int i, int v) {
    for (; i<MN; i+=i&-i) F[i] += v;
  }

  lld qry(int i) {
    lld ret = 0;
    for (; i>0; i-=i&-i) ret += F[i];
    return ret;
  }
} FA, FB;

void add(int i) {
  cntA[A[i]]++;
  cntB[B[i]]++;
  FA.upd(A[i], 1);
  FB.upd(B[i], 1);
}

void del(int i) {
  cntA[A[i]]--;
  cntB[B[i]]--;
  FA.upd(A[i], -1);
  FB.upd(B[i], -1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int i=1; i<=N; i++) cin >> B[i];
  cin >> M;
  for (int i=0; i<M; i++) {
    int l, r, k; cin >> l >> r >> k;
    Q[i] = {l, r, k, i};
  }
  sort(Q, Q+M);

  int l=1, r=0;
  for (int i=0; i<M; i++) {
    while (Q[i].l < l) add(--l);
    while (r < Q[i].r) add(++r);

    while (l < Q[i].l) del(l++);
    while (Q[i].r < r) del(r--);

    int j = 1;
    for (; j*j<=Q[i].k; j++) {
      ans[Q[i].i] += cntA[j] * FB.qry(Q[i].k / j);
      ans[Q[i].i] += cntB[j] * FA.qry(Q[i].k / j);
    }
    j--;
    ans[Q[i].i] -= FA.qry(j) * FB.qry(j);
  }

  for (int i=0; i<M; i++) cout << ans[i] << endl;

  ////////////////////////////////
  return 0;
}
