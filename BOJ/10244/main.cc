#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, A[MN], D[MN][105], cnt[105];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  while (true) {
    cin >> N;
    if (N == 0) break;
    for (int i=1; i<=N; i++) {
      cin >> A[i];
      fill(D[i], D[i]+105, 0);
    }
    fill(cnt, cnt+105, 0);

    for (int i=1; i<=N; i++) {
      for (int j=1; j<=100; j++) {
        if (D[i-1][j]) {
          int g = gcd(j, A[i]);
          D[i][g] = 1;
          cnt[g]++;
        }
      }
      D[i][A[i]] = 1;
      cnt[A[i]]++;
    }

    int ans = 0;
    for (int i=1; i<=100; i++) {
      if (cnt[i] > 0) ans++;
    }
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
