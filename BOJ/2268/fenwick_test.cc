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

////////////////////////////////////////////////////////////////

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int N, M;
  cin >> N >> M;
  vector<lld> A(N+1);
  fenwick_tree F(N);

  for (int i=0; i<M; i++) {
    int q, a, b; cin >> q >> a >> b;
    if (q == 0) {
      if (a > b) swap(a, b);
      cout << F.sum(b) - F.sum(a-1) << endl;
    } else {
      F.add(a, b-A[a]);
      A[a] = b;
    }
  }

  ////////////////////////////////
  return 0;
}
