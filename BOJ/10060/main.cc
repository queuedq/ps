#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
lld N, K, sp[21][MN*2];
pii A[MN];

lld nxt(lld i, lld j) {
  return sp[j][i%N] + i/N*N;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<K; i++) {
    int a, b; cin >> a >> b; a--; b--;
    if (a > b) b += N;
    A[i] = {a, b};
  }

  fill(sp[0], sp[0]+N, -1);

  sort(A, A+K);
  int l = 0, r = 0;
  for (int i=0; i<K; i++) {
    while (l < min(r, A[i].first)) sp[0][l++] = r;
    l = A[i].first;
    r = max(r, A[i].second+1);
  }
  while (l < r) {
    if (l < N) sp[0][l] = r;
    else sp[0][l-N] = max(sp[0][l-N], r-N);
    l++;
  }
  
  for (int i=0; i<N; i++) {
    if (sp[0][i] == -1) {
      cout << "impossible" << endl;
      return 0;
    }
  }

  for (int j=1; j<=20; j++) {
    for (int i=0; i<N; i++) {
      sp[j][i] = nxt(nxt(i, j-1), j-1);
    }
  }

  int ans = K;
  for (int s=0; s<N; s++) {
    int i = s, cnt = 1;
    for (int j=20; j>=0; j--) {
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
