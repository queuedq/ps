#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
const int ST = 1<<18;
lld N, Q, A[MN], tmp[MN], seg[ST*2];
vector<lld> xs;

struct Query { lld t, i, x, l, r; };
Query qry[MN];

int compress(lld x) {
  return lower_bound(all(xs), x) - xs.begin();
}

void upd(int i, int x) {
  seg[i += ST] += x;
  for (i/=2; i>0; i/=2) seg[i] = seg[i*2] + seg[i*2+1];
}

int sum(int l, int r) { // [l, r]
  int res = 0;
  for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
    if (l&1) res += seg[l++];
    if (r&1) res += seg[--r];
  }
  return res;
}

int kth(int n, int k) {
  if (n >= ST) return n-ST;
  if (k <= seg[n*2]) return kth(n*2, k);
  return kth(n*2+1, k - seg[n*2]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> Q;
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int q=0; q<Q; q++) {
    lld t, i, x, l, r;
    cin >> t;
    if (t <= 2) {
      cin >> i >> x;
      if (t == 2) t = 1, x = -x;
      qry[q] = {t, i, x, 0, 0};
    }
    if (t == 3) { cin >> l >> r; qry[q] = {t, 0, 0, l, r}; }
    if (t == 4) { cin >> x; qry[q] = {t, 0, x, 0, 0}; }
  }

  // pre-simulate
  for (int i=1; i<=N; i++) xs.push_back(tmp[i] = A[i]);
  for (int q=0; q<Q; q++) {
    auto [t, i, x, l, r] = qry[q];
    if (t <= 2) xs.push_back(tmp[i] += x);
    if (t == 3) xs.push_back(l), xs.push_back(r);
  }

  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());

  // queries
  for (int i=1; i<=N; i++) upd(compress(A[i]), 1);
  for (int q=0; q<Q; q++) {
    auto [t, i, x, l, r] = qry[q];
    if (t <= 2) {
      upd(compress(A[i]), -1);
      A[i] += x;
      upd(compress(A[i]), 1);

    } else if (t == 3) {
      int L = compress(l), R = compress(r);
      cout << sum(L, R) << endl;

    } else if (t == 4) {
      cout << xs[kth(1, N-x+1)] << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
