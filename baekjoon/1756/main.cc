#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAX = 300'000;
int D, N;
int oven[MAX], pizza[MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> D >> N;
  for (int i = 0; i < D; i++) { cin >> oven[i]; }
  for (int i = 0; i < N; i++) { cin >> pizza[i]; }

  for (int i = 1; i < D; i++) {
    if (oven[i] > oven[i-1]) { oven[i] = oven[i-1]; }
  }

  int cnt = 0, ans = 0;
  for (int i = D-1; i >= 0; i--) {
    if (oven[i] >= pizza[cnt]) {
      cnt++;
      ans = i+1;
    }
    if (cnt == N) break;
  }

  if (cnt < N) ans = 0;
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
