#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, K, M, A[MN], D[MN], cnt[MN];

bool check(int m) {
  fill(cnt, cnt+D[0]+1, 0);
  for (int j=0; j<m; j++) cnt[D[j]]++;

  lld cur = K, nxt = 0;
  for (int d=0, i=0; d<=D[0]; d++) {
    // fill with devices
    if (cur < cnt[d]) return 0;
    cur -= cnt[d];
    m -= cnt[d];

    // fill with multi plugs
    while (cur > 0 && i < N) cur--, nxt += A[i++];

    if (i == N) return cur + nxt >= m; // out of multi plugs
    else cur = nxt, nxt = 0;
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K >> M;
  for (int i=0; i<N; i++) cin >> A[i];
  for (int j=0; j<M; j++) cin >> D[j];

  sort(A, A+N); reverse(A, A+N);
  sort(D, D+M); reverse(D, D+M);

  int l = 0, r = M+1;
  while (l+1 < r) {
    int m = (l+r)/2;
    if (check(m)) l = m;
    else r = m;
  }
  
  cout << l << endl;

  ////////////////////////////////
  return 0;
}
