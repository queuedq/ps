#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
lld N, L;
pll A[MAXN*2];
lld nxt[MAXN];

lld step(lld i) { return nxt[i%N] + i/N*N; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> L;
  for (int i=0; i<N; i++) {
    lld s, e; cin >> s >> e;
    if (s > e) swap(s, e);
    if (e-s > L/2) { swap(s, e); s -= L; }
    A[i] = {e, s};
    A[i+N] = {e+L, s+L};
  }

  sort(A, A+N*2);

  int j = 0;
  for (int i=0; i<N; i++) {
    while (A[j].second <= A[i].first) j++;
    nxt[i] = j;
  }

  lld i = 0;
  for (int k=0; k<N; k++) i = step(i);

  lld s = i, ans = 0;
  for (; i-s < N; i = step(i)) ans++;

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
