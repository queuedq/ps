#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 250'005;
int N, K, M, A[MN], bit[MN];
set<int> zero[30];

void update(int i, int v) {
  for (; i <= N; i += i&-i) bit[i] += v;
}

int query(int i) {
  int sum = 0;
  for (; i > 0; i -= i&-i) sum += bit[i];
  return sum;
} 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;

  for (int i=1; i<=N; i++) {
    cin >> A[i];
    for (int k=0; k<30; k++) {
      if (!(A[i] & 1<<k)) zero[k].insert(i);
    }
    if (A[i] == K) update(i, 1);
  }

  cin >> M;

  for (int i=0; i<M; i++) {
    int t, l, r, x; cin >> t >> l >> r;
    if (t == 1) {
      cin >> x;
      for (int k=0; k<30; k++) {
        if (!(x & 1<<k)) continue;
        auto it = zero[k].lower_bound(l);
        while (it != zero[k].end() && *it <= r) {
          if (A[*it] == K) update(*it, -1);
          A[*it] |= 1<<k;
          if (A[*it] == K) update(*it, 1);
          it = zero[k].erase(it);
        }
      }
    } else {
      cout << query(r) - query(l-1) << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
