#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

struct SegTree {
  vector<lld> add, step;
  int size;

  SegTree(const vector<lld> &arr) {
    size = 1 << (int)ceil(log2(arr.size()));
    add.resize(size*2);
    step.resize(size*2);
    for (int i=0; i<arr.size(); i++) add[size+i+1] = arr[i];
  }

  void propagate(int n, int nl, int nr) {
    if (n < size) {
      int mid = (nl+nr)/2;
      add[n*2] += add[n];
      add[n*2+1] += add[n] + step[n]*(mid-nl);
      step[n*2] += step[n];
      step[n*2+1] += step[n];
      add[n] = 0;
      step[n] = 0;
    }
  }

  void update_range(int l, int r) { update_range(1, 0, size, l, r); }
  void update_range(int n, int nl, int nr, int l, int r) {
    propagate(n, nl, nr);
    if (nr <= l || r <= nl) return;
    if (l <= nl && nr <= r) {
      add[n] += nl-l+1;
      step[n]++;
      return propagate(n, nl, nr);
    }
    int mid = (nl+nr)/2;
    update_range(n*2, nl, mid, l, r);
    update_range(n*2+1, mid, nr, l, r);
  }

  lld query(int i) { return query(1, 0, size, i); }
  lld query(int n, int nl, int nr, int i) {
    while (nl+1 < nr) {
      propagate(n, nl, nr);
      int mid = (nl+nr)/2;
      if (i < mid) { n = n*2; nr = mid; }
      else { n = n*2+1; nl = mid; }
    }
    return add[n];
  }
};

int N, Q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  vector<lld> A(N);
  for (int i=0; i<N; i++) cin >> A[i];

  SegTree seg(A);
  cin >> Q;
  for (int i=0; i<Q; i++) {
    int q, L, R, X; cin >> q;
    if (q == 1) {
      cin >> L >> R;
      seg.update_range(L, R+1);
    } else {
      cin >> X;
      cout << seg.query(X) << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
