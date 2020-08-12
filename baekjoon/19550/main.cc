#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, L;
pii A[MAXN*2];
lld sp[20][MAXN];

lld nxt(lld i, lld j) {
  return sp[j][i%N] + i/N*N;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> L;
  for (int i=0; i<N; i++) {
    int s, e; cin >> s >> e;
    if (s > e) swap(s, e);
    if (e-s > L/2) { e -= L; swap(s, e); }
    A[i] = {e, s};
    A[i+N] = {e+L, s+L};
  }

  sort(A, A+N*2);

  int j = 0;
  for (int i=0; i<N; i++) {
    while (A[j].second <= A[i].first) j++;
    sp[0][i] = j;
    // assert(j < N*2);
  }

  for (int j=1; j<20; j++) {
    for (int i=0; i<N; i++) {
      sp[j][i] = nxt(nxt(i, j-1), j-1);
    }
  }

  int ans = N;
  for (int s=0; s<N; s++) {
    int i = s, cnt = 1;
    for (int j=19; j>=0; j--) {
      if (nxt(i, j) - s < N) {
        i = nxt(i, j);
        cnt += 1<<j;
      }
    }
    ans = min(ans, cnt);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
