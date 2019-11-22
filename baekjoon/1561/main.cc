#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const lld MAX_N = (lld)2e9 + 5;
const lld MAX_M = 10005;
lld N, M, T[MAX_M];

lld numAt(lld t) {
  lld num = 0;
  for (int i = 0; i < M; i++) {
    num += t / T[i] + (t % T[i] != 0);
  }
  return num;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> T[i];
  }

  lld l = 0, r = MAX_N * 30;
  while (l + 1 < r) {
    lld mid = (l + r) / 2;
    if (numAt(mid) >= N) r = mid;
    else l = mid;
  }

  lld avail = N - numAt(l);
  lld ans = -1;
  for (int i = 0; i < M; i++) {
    if (l % T[i] == 0) {
      avail--;
      if (avail == 0) {
        ans = i + 1;
        break;
      }
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
