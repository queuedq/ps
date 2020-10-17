#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
lld N, K, A[MAXN], cuts[MAXN];

lld cost(lld a, lld k) {
  lld q = a/k, r = a%k;
  return q*q*(k-r) + (q+1)*(q+1)*r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    cuts[i] = 1;
  }

  priority_queue<pll> pq;
  for (int i=0; i<N; i++) {
    pq.push({cost(A[i], 1) - cost(A[i], 2), i});
  }

  for (int k=0; k<K-N; k++) {
    auto [dec, i] = pq.top(); pq.pop();
    cuts[i]++;
    pq.push({cost(A[i], cuts[i]) - cost(A[i], cuts[i]+1), i});
  }

  lld ans = 0;
  for (int i=0; i<N; i++) {
    ans += cost(A[i], cuts[i]);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
