#include <bits/stdc++.h>
using namespace std;
using lld = long long;
using pll = pair<lld, lld>;

const int MN = 300'005;
lld N, H[MN], T[MN], D[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  for (int i=1; i<=N; i++) cin >> H[i];
  for (int i=1; i<=N-1; i++) cin >> T[i];

  int j = 1;
  lld t = 0;
  for (int i=1; i<=N; i++) {
    while (t > H[i]) {
      D[j] = H[i-1];
      t -= T[j];
      j++;
    }
    t += T[i];
  }
  while (j <= N) {
    D[j] = H[N];
    t -= T[j];
    j++;
  }

  for (int i=1; i<=N; i++) cout << D[i] << " ";

  return 0;
}
