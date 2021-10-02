#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
const int MH = 5e7; // > 9**8
int N, K, idx=1, p9[8], A[MN], cnt[MH];

void subsets(int i, int sub, int S, int v) {
  if (i == K) { cnt[sub] += v; return; }
  for (int j=0; j<=S%9; j++) {
    subsets(i+1, sub + p9[i]*j, S/9, v);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  p9[0] = 1;
  for (int i=1; i<K; i++) p9[i] = p9[i-1] * 9;

  for (int i=0; i<N; i++) {
    char q; cin >> q;
    if (q == 'C') {
      int R; cin >> R;
      for (int j=0; j<R; j++) { int T; cin >> T; A[idx] += p9[T-1]; }

      subsets(0, 0, A[idx], 1);
      idx++;
    }

    if (q == 'D') {
      int x; cin >> x;
      subsets(0, 0, A[x], -1);
    }

    if (q == 'J') {
      int R; cin >> R;
      int S = 0;
      for (int j=0; j<R; j++) { int T; cin >> T; S += p9[T-1]; }

      cout << cnt[S] << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
