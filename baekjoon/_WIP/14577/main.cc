#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct fenwick_tree {
  vector<lld> A;

  fenwick_tree(int size) { A.resize(size+1); }

  void reset() { fill(A.begin(), A.end(), 0); }

  // Adds x to A[i]
  void add(int i, lld x) {
    assert(1 <= i && i <= A.size()-1);
    for (; i < A.size(); i += i&-i) A[i] += x;
  }

  // Returns sum of A[1..i]
  lld sum(int i) {
    assert(0 <= i && i <= A.size()-1);
    lld s = 0;
    for (; i > 0; i -= i&-i) s += A[i];
    return s;
  }
};

int compress(lld x, const vector<lld> &xs) {
  return lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1;
}

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
lld N, M, S[MAXN], tmp[MAXN];
vector<lld> xs;

struct Query { lld q, i, x, l, r, t; };
vector<Query> Q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) {
    cin >> S[i];
    tmp[i] = S[i];
    xs.push_back(S[i]);
  }

  for (int j=0; j<M; j++) {
    lld q, i, x, l, r, t; cin >> q;
    if (q <= 2) {
      cin >> i >> x;
      if (q == 2) x = -x;
      Q.push_back({q, i, x, 0, 0, 0});
      tmp[i] += x;
      xs.push_back(tmp[i]);
    }
    if (q == 3) { cin >> l >> r; Q.push_back({q, 0, 0, l, r, 0}); }
    if (q == 4) { cin >> t; Q.push_back({q, 0, 0, 0, 0, t}); }
  }

  sort(xs.begin(), xs.end());
  xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

  fenwick_tree F(xs.size());
  for (int i=1; i<=N; i++) {
    F.add(compress(S[i], xs), 1);
  }

  for (int j=0; j<M; j++) {
    if (Q[j].q <= 2) {
      lld i = Q[j].i, x = Q[j].x;
      F.add(compress(S[i], xs), -1);
      S[i] += x;
      F.add(compress(S[i], xs), 1);
    }

    if (Q[j].q == 3) {
      lld ri = compress(Q[j].r+1, xs)-1;
      lld li = compress(Q[j].l, xs);
      cout << F.sum(ri) - F.sum(li-1) << endl;
    }

    if (Q[j].q == 4) {
      lld l = 0, r = xs.size();
      while (l+1 < r) {
        lld m = (l+r) / 2;
        if (F.sum(m) >= Q[j].t) r = m;
        else l = m;
      }
      cout << xs[r-1] << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
