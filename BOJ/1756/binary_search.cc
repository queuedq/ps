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
  for (int i = D-1; i >= 0; i--) { cin >> oven[i]; }
  for (int i = 0; i < N; i++) { cin >> pizza[i]; }

  for (int i = D-2; i >= 0; i--) {
    if (oven[i] > oven[i+1]) { oven[i] = oven[i+1]; }
  }

  int bottom = 0;
  for (int i = 0; i < N; i++) {
    int stuck = lower_bound(oven+bottom, oven+D, pizza[i]) - oven;
    if (stuck == D) { cout << 0; return 0; }
    else { bottom = stuck + 1; }
  }

  cout << D - bottom + 1 << endl;

  ////////////////////////////////
  return 0;
}
