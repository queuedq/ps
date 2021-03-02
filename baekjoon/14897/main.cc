#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
const int B = 1024;
int N, Q, A[MN], xs[MN], cnt[MN], ans[MN];

struct Query {
  int l, r, i;
  bool operator <(const Query &q) const {
    return (l/B == q.l/B) ? (r/B < q.r/B) : (l/B < q.l/B);
  }
} qry[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) { cin >> A[i]; xs[i-1] = A[i]; }
  cin >> Q;
  for (int i=0; i<Q; i++) { int l, r; cin >> l >> r; qry[i] = {l, r, i}; }

  sort(xs, xs+N);
  for (int i=1; i<=N; i++) A[i] = lower_bound(xs, xs+N, A[i]) - xs;
  sort(qry, qry+Q);

  for (int i=0, l=1, r=0, d=0; i<Q; i++) {
    while (qry[i].l < l) { cnt[A[--l]]++; if (cnt[A[l]] == 1) d++; }
    while (r < qry[i].r) { cnt[A[++r]]++; if (cnt[A[r]] == 1) d++; }
    while (l < qry[i].l) { cnt[A[l]]--; if (cnt[A[l++]] == 0) d--; }
    while (qry[i].r < r) { cnt[A[r]]--; if (cnt[A[r--]] == 0) d--; }
    ans[qry[i].i] = d;
  }

  for (int i=0; i<Q; i++) cout << ans[i] << endl;

  ////////////////////////////////
  return 0;
}
