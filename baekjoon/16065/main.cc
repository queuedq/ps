#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAX_N = 1e6 + 5;
int N, A[MAX_N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i = 0; i < N; i++) { cin >> A[i]; }

  int lower = 0, upper = A[0];
  for (int i = 0; i < N; i++) {
    int temp = lower;
    lower = A[i] - upper;
    upper = A[i] - temp;

    lower = max(lower, 0);
    if (i < N - 1) upper = min(upper, A[i+1]);

    if (lower > upper) {
      cout << 0 << endl;
      return 0;
    }
  }

  cout << upper - lower + 1 << endl;

  ////////////////////////////////
  return 0;
}
