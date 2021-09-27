#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010101;
lld N, M, K, A[MN];

struct fenwick_tree {
  vector<lld> F;

  fenwick_tree(int sz) { F.resize(sz+1); }

  void add(int i, lld x) {
    for (; i<F.size(); i += i&-i) F[i] += x;
  }

  lld sum(int i) { // [1, i]
    lld s = 0;
    for (; i>0; i -= i&-i) s += F[i];
    return s;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;
  fenwick_tree bit(N);
  for (int i=1; i<=N; i++) {
    cin >> A[i];
    bit.add(i, A[i]);
  }

  for (int i=0; i<M+K; i++) {
    lld a, b, c; cin >> a >> b >> c;
    if (a == 1) {
      bit.add(b, c - A[b]);
      A[b] = c;
    } else {
      cout << bit.sum(c) - bit.sum(b-1) << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
